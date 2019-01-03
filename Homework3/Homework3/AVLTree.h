#ifndef AVLTREE_H_
#define AVLTREE_H_


#include<iostream>
#include<iomanip>
using namespace std;


template <typename T>
struct AVLElement {
	T data;
	int balance;
	AVLElement<T> *left, *right;
};


template <typename T>
class AVLTree {
private:
	AVLElement<T>* root;
	void deleteTree(AVLElement<T>* &) const;
	void copy(AVLElement<T>* &, AVLElement<T>* const&) const;
	void copyTree(AVLTree<T> const&);
	void printFromNode(AVLElement<T> const*, ostream&, int) const;
	int sizeFromNode(AVLElement<T> const*) const;

	int add(AVLElement<T>* &, T const&) const;
	int deleteNodePtr(AVLElement<T>* &, T const&) const;

	void leftRotate(AVLElement<T>* &) const;
	void rightRotate(AVLElement<T>* &) const;
public:
	AVLTree();
	AVLTree(AVLTree<T> const&);
	AVLTree<T>& operator=(AVLTree<T> const&);
	~AVLTree();

	T getRootData() const;
	int getRootBalance() const;

	AVLTree<T> leftTree() const;
	AVLTree<T> rightTree() const;

	bool empty() const;
	int size() const;
	void input(AVLElement<T>*&, istream&);
	void print(ostream&) const;

	void addNode(T const&);
	void deleteNode(T const&);

	void create();

	template <typename U>
	friend istream& operator>> (istream&, AVLTree<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, AVLTree<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, AVLTree<U>&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, AVLTree<U>&);
	template <typename U>
	friend bool operator< (AVLTree<U> const&, AVLTree<U> const&);
};


template <typename T>
void AVLTree<T>::deleteTree(AVLElement<T>*& t) const {
	if (t == NULL) return;
	deleteTree(t->left); deleteTree(t->right);
	delete t;
	t = NULL;
}
template <typename T>
void AVLTree<T>::copy(AVLElement<T>*& to, AVLElement<T>* const& from) const {
	if (from == NULL) {
		to = from;
		return;
	}
	to = new AVLElement<T>;
	to->data = from->data; to->balance = from->balance;
	copy(to->left, from->left);
	copy(to->right, from->right);
}
template <typename T>
void AVLTree<T>::copyTree(AVLTree<T> const& t) {
	copy(root, t.root);
}
template <typename T>
void AVLTree<T>::printFromNode(AVLElement<T> const* t, ostream& out, int pos) const {
	if (t == NULL) return;
	pos += 7;
	printFromNode(t->left, out, pos);
	out << setw(pos) << t->data << " " << t->balance << endl;
	printFromNode(t->right, out, pos);
}
template <typename T>
int AVLTree<T>::sizeFromNode(AVLElement<T> const* t) const {
	if (t == NULL) return 0;
	return 1 + sizeFromNode(t->left) + sizeFromNode(t->right);
}


template <typename T>
int AVLTree<T>::add(AVLElement<T>*& t, T const& data) const {
	if (t == NULL) {
		t = new AVLElement<T>;
		t->data = data; t->balance = 0;
		t->left = t->right = NULL;
		return 1;
	}
	if (t->data > data) {
		if (add(t->left, data) == 1) {
			t->balance--;
			if (t->balance == -1) return 1;
			if (t->balance == -2) {
				if (t->left->balance == 1) leftRotate(t->left);
				rightRotate(t);
			}
		}
		return 0;
	}
	else {
		if (add(t->right, data) == 1) {
			t->balance++;
			if (t->balance == 1) return 1;
			if (t->balance == 2) {
				if (t->right->balance == -1) rightRotate(t->right);
				leftRotate(t);
			}
		}
		return 0;
	}
}
template <typename T>
int AVLTree<T>::deleteNodePtr(AVLElement<T>*& t, T const& data) const {
	if (t == NULL) {
		cerr << "The element is not in the tree\n";
		return 0;
	}
	if (t->data == data) {
		AVLElement<T>* temp;
		if (t->left == NULL) {
			temp = t;
			t = t->right;
			delete temp;
			return 1;
		}
		if (t->right == NULL) {
			temp = t;
			t = t->left;
			delete temp;
			return 1;
		}
		temp = t->right;
		for (;;) {
			if (temp->left == NULL) break;
			temp = temp->left;
		}
		t->data = temp->data;
		if (deleteNodePtr(t->right, temp->data) == 1) {
			t->balance--;
			if (t->balance == 0) return 1;
			if (t->balance == -1) return 0;
			if (t->balance == -2) {
				if (t->left->balance == 1) leftRotate(t->left);
				rightRotate(t);
				if (t->balance == 0) return 1;
				return 0;
			}
		}
		return 0;
	}
	if (t->data > data) {
		if (deleteNodePtr(t->left, data) == 1) {
			t->balance++;
			if (t->balance == 0) return 1;
			if (t->balance == 1) return 0;
			if (t->balance == 2) {
				if (t->right->balance == -1) rightRotate(t->right);
				leftRotate(t);
				if (t->balance == 0) return 1;
				return 0;
			}
		}
		return 0;
	}
	else {
		if (deleteNodePtr(t->right, data) == 1) {
			t->balance--;
			if (t->balance == 0) return 1;
			if (t->balance == -1) return 0;
			if (t->balance == -2) {
				if (t->left->balance == 1) leftRotate(t->left);
				rightRotate(t);
				if (t->balance == 0) return 1;
				return 0;
			}
		}
		return 0;
	}
}


template <typename T>
void AVLTree<T>::leftRotate(AVLElement<T>*& t) const {
	AVLElement<T>* temp;
	temp = t->right;
	t->right = t->right->left;
	temp->left = t;
	t = temp;

	t->left->balance--;
	if (t->balance > 0) t->left->balance -= t->balance;
	t->balance--;
	if (t->left->balance < 0) t->balance += t->left->balance;
}
template <typename T>
void AVLTree<T>::rightRotate(AVLElement<T>*& t) const {
	AVLElement<T>* temp;
	temp = t->left;
	t->left = t->left->right;
	temp->right = t;
	t = temp;

	t->right->balance++;
	if (t->balance < 0) t->right->balance -= t->balance;
	t->balance++;
	if (t->right->balance > 0) t->balance += t->right->balance;
}


template <typename T>
AVLTree<T>::AVLTree() {
	root = NULL;
}
template <typename T>
AVLTree<T>::AVLTree(AVLTree<T> const& rhs) {
	copyTree(rhs);
}
template <typename T>
AVLTree<T>& AVLTree<T>::operator= (AVLTree<T> const& rhs) {
	if (this == &rhs) return *this;
	deleteTree(root);
	copyTree(rhs);
	return *this;
}
template <typename T>
AVLTree<T>::~AVLTree() {
	deleteTree(root);
}


template <typename T>
T AVLTree<T>::getRootData() const {
	return root->data;
}
template <typename T>
int AVLTree<T>::getRootBalance() const {
	return root->balance;
}


template <typename T>
AVLTree<T> AVLTree<T>::leftTree() const {
	AVLTree<T> t;
	copy(t.root, root->left);
	return t;
}
template <typename T>
AVLTree<T> AVLTree<T>::rightTree() const {
	AVLTree<T> t;
	copy(t.root, root->right);
	return t;
}


template <typename T>
bool AVLTree<T>::empty() const {
	if (root == NULL) return true;
	return false;
}
template <typename T>
int AVLTree<T>::size() const {
	return sizeFromNode(root);
}
template <typename T>
void AVLTree<T>::input(AVLElement<T>*& t, istream& in) {
	deleteTree(root);
	int n, i;
	T data;
	in >> n;
	for (i = 0; i < n; i++) {
		in >> data;
		addNode(data);
	}
}
template <typename T>
void AVLTree<T>::print(ostream& out) const {
	printFromNode(root, out, 0);
}


template <typename T>
void AVLTree<T>::addNode(T const& data) {
	add(root, data);
}
template <typename T>
void AVLTree<T>::deleteNode(T const& data) {
	deleteNodePtr(root, data);
}


template <typename T>
void AVLTree<T>::create() {
	input(cin);
}


template <typename T>
istream& operator>> (istream& in, AVLTree<T>& obj) {
	obj.input(obj.root, in);
	return in;
}
template <typename T>
ostream& operator<< (ostream& out, AVLTree<T>& obj) {
	obj.print(out);
	return out;
}
template <typename T>
ifstream& operator>> (ifstream& fin, AVLTree<T>& obj) {
	obj.input(obj.root, fin);
	return fin;
}
template <typename T>
ofstream& operator<< (ofstream& fout, AVLTree<T>& obj) {
	obj.print(fout);
	return fout;
}
template <typename T>
bool operator< (AVLTree<T> const& obj1, AVLTree<T> const& obj2) {
	return (obj1.size() < obj2.size());
}


#endif
