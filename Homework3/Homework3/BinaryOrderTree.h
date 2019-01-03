#ifndef BINARYORDERTREE_H_
#define BINARYORDERTREE_H_


#include<iostream>
using namespace std;


template <typename T>
struct TreeElement {
	T data;
	TreeElement<T> *left, *right;
};


template <typename T>
class BinOrderTree {
private:
	TreeElement<T>* root;
	void deleteTree(TreeElement<T>* &) const;
	void copy(TreeElement<T>* &, TreeElement<T>* const&) const;
	void copyTree(BinOrderTree<T> const&);
	void printFromNode(TreeElement<T> const*, ostream&) const;
	int sizeFromNode(TreeElement<T> const*) const;

	void add(TreeElement<T>* &, T const&) const;
	void deleteNodePtr(TreeElement<T>* &, T const&) const;
public:
	BinOrderTree();
	BinOrderTree(BinOrderTree<T> const&);
	BinOrderTree<T>& operator=(BinOrderTree<T> const&);
	~BinOrderTree();

	T getRootData() const;
	TreeElement<T>* getRootPtr() const;
	
	BinOrderTree<T> leftTree() const;
	BinOrderTree<T> rightTree() const;

	bool empty() const;
	int size() const;
	void input(TreeElement<T>*&, istream&);
	void print(ostream&) const;

	void addNode(T const&);
	void deleteNode(T const&);

	void createWithData(T const&, BinOrderTree<T> const&, BinOrderTree<T> const&);
	void create();

	template <typename U>
	friend istream& operator>> (istream&, BinOrderTree<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, BinOrderTree<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, BinOrderTree<U>&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, BinOrderTree<U>&);
	template <typename U>
	friend bool operator< (BinOrderTree<U> const&, BinOrderTree<U> const&);
};


template <typename T>
void BinOrderTree<T>::deleteTree (TreeElement<T>*& t) const {
	if (t == NULL) return;
	deleteTree(t->left); deleteTree(t->right);
	delete t;
	t = NULL;
}
template <typename T>
void BinOrderTree<T>::copy (TreeElement<T>*& to, TreeElement<T>* const& from) const {
	if (from == NULL) {
		to = from;
		return;
	}
	to = new TreeElement<T>;
	to->data = from->data;
	copy(to->left, from->left);
	copy(to->right, from->right);
}
template <typename T>
void BinOrderTree<T>::copyTree(BinOrderTree<T> const& t) {
	copy(root, t.root);
}
template <typename T>
void BinOrderTree<T>::printFromNode(TreeElement<T> const* t, ostream& out) const {
	if (t == NULL) return;
	printFromNode(t->left, out);
	out << t->data << " ";
	printFromNode(t->right, out);
}
template <typename T>
int BinOrderTree<T>::sizeFromNode(TreeElement<T> const* t) const {
	if (t == NULL) return 0;
	return 1 + sizeFromNode(t->left) + sizeFromNode(t->right);
}


template <typename T>
void BinOrderTree<T>::add (TreeElement<T>*& t, T const& data) const {
	if (t == NULL) {
		t = new TreeElement<T>;
		t->data = data;
		t->left = t->right = NULL;
		return;
	}
	if (t->data > data) add(t->left, data);
	else add(t->right, data);
}
template <typename T>
void BinOrderTree<T>::deleteNodePtr(TreeElement<T>*& t, T const& data) const {
	if (t == NULL) {
		cerr << "The element is not in the tree\n";
		return;
	}
	TreeElement<T>* temp;
	if (t->data == data) {
		if (t->left == NULL) {
			temp = t;
			t = t->right;
			delete temp;
			return;
		}
		if (t->right == NULL) {
			temp = t;
			t = t->left;
			delete temp;
			return;
		}
		temp = t->right;
		for (;;) {
			if (temp->left == NULL) break;
			temp = temp->left;
		}
		t->data = temp->data;
		deleteNodePtr(t->right, temp->data);
		return;
	}
	if (t->data > data) deleteNodePtr(t->left, data);
	else deleteNodePtr(t->right, data);
}


template <typename T>
BinOrderTree<T>::BinOrderTree() {
	root = NULL;
}
template <typename T>
BinOrderTree<T>::BinOrderTree(BinOrderTree<T> const& rhs) {
	copyTree(rhs);
}
template <typename T>
BinOrderTree<T>& BinOrderTree<T>::operator= (BinOrderTree<T> const& rhs) {
	if (this == &rhs) return *this;
	deleteTree(root);
	copyTree(rhs);
	return *this;
}
template <typename T>
BinOrderTree<T>::~BinOrderTree() {
	deleteTree(root);
}


template <typename T>
T BinOrderTree<T>::getRootData() const {
	return root->data;
}
template <typename T>
TreeElement<T>* BinOrderTree<T>::getRootPtr() const {
	return root;
}


template <typename T>
BinOrderTree<T> BinOrderTree<T>::leftTree() const {
	BinOrderTree<T> t;
	copy(t.root, root->left);
	return t;
}
template <typename T>
BinOrderTree<T> BinOrderTree<T>::rightTree() const {
	BinOrderTree<T> t;
	copy(t.root, root->right);
	return t;
}


template <typename T>
bool BinOrderTree<T>::empty() const {
	if (root == NULL) return true;
	return false;
}
template <typename T>
int BinOrderTree<T>::size() const {
	return sizeFromNode(root);
}
template <typename T>
void BinOrderTree<T>::input(TreeElement<T>*& t, istream& in) {
	deleteTree(t);
	int n, i;
	T data;
	in >> n;
	for (i = 0; i < n; i++) {
		in >> data;
		addNode(data);
	}
}
template <typename T>
void BinOrderTree<T>::print(ostream& out) const {
	printFromNode(root, out);
	out << "\n";
}


template <typename T>
void BinOrderTree<T>::addNode(T const& data) {
	add(root, data);
}
template <typename T>
void BinOrderTree<T>::deleteNode(T const& data) {
	deleteNodePtr(root, data);
}


template <typename T>
void BinOrderTree<T>::createWithData(T const& data, BinOrderTree<T> const& left, BinOrderTree<T> const& right) {
	root = new TreeElement<T>;
	root->data = data;
	copy(root->left, left.root); copy(root->right, right.root);
}
template <typename T>
void BinOrderTree<T>::create() {
	input(cin);
}


template <typename T>
istream& operator>> (istream& in, BinOrderTree<T>& obj) {
	obj.input(obj.root, in);
	return in;
}
template <typename T>
ostream& operator<< (ostream& out, BinOrderTree<T>& obj) {
	obj.print(out);
	return out;
}
template <typename T>
ifstream& operator>> (ifstream& fin, BinOrderTree<T>& obj) {
	obj.input(obj.root, fin);
	return fin;
}
template <typename T>
ofstream& operator<< (ofstream& fout, BinOrderTree<T>& obj) {
	obj.print(fout);
	return fout;
}
template <typename T>
bool operator< (BinOrderTree<T> const& obj1, BinOrderTree<T> const& obj2) {
	return (obj1.size() < obj2.size());
}


#endif
