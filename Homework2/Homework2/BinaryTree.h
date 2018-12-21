#ifndef BINARYTREE_H_
#define BINARYTREE_H_


#include <iostream>
using namespace std;


template <typename T>
struct TreeElement {
	T data;
	TreeElement<T> *left, *right;
};

template <typename T>
class BinTree {
private:
	TreeElement<T>* root;

	void deleteBinTree(TreeElement<T>*&) const;
	void copy(TreeElement<T>*&, TreeElement<T>* const&) const;
	void copyBinTree(BinTree<T> const&);

	void printFromNode(TreeElement<T> const*, ostream&) const;
	int sizeFromNode(TreeElement<T> const*) const;
	void createBinTree(TreeElement<T>*&, int) const;
public:
	BinTree();
	BinTree(BinTree<T> const&);
	BinTree<T>& operator=(BinTree<T> const&);
	~BinTree();

	BinTree<T> leftBinTree() const;
	BinTree<T> rightBinTree() const;

	T getRootData() const;
	TreeElement<T>* getRootPointer();

	bool empty() const;
	int size() const;
	void input(TreeElement<T>*&, istream&);
	void print(ostream&) const;

	void deleteTree();
	void create(int);
	void createWithData(T, BinTree<T>, BinTree<T>);

	template <typename U>
	friend istream& operator>> (istream&, BinTree<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, BinTree<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, BinTree<U>&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, BinTree<U>&);
	template <typename U>
	friend bool operator< (BinTree<U> const&, BinTree<U> const&);
};


template <typename T>
void BinTree<T>::deleteBinTree(TreeElement<T>*& t) const {
	if (t == NULL) return;
	deleteBinTree(t->left); deleteBinTree(t->right);
	delete t;
	t = NULL;
}
template <typename T>
void BinTree<T>::copy(TreeElement<T>*& to, TreeElement<T>* const& from) const {
	if (from == NULL) {
		to = NULL;
		return;
	}
	to = new TreeElement<T>;
	to->data = from->data;
	copy(to->left, from->left); copy(to->right, from->right);
}
template <typename T>
void BinTree<T>::copyBinTree(BinTree<T> const& from) {
	copy(root, from.root);
}


template <typename T>
void BinTree<T>::printFromNode(TreeElement<T> const* t, ostream& out) const {
	if (t == NULL) return;
	printFromNode(t->left, out);
	out << t->data << " ";
	printFromNode(t->right, out);
}
template <typename T>
int BinTree<T>::sizeFromNode(TreeElement<T> const* t) const {
	if (t == NULL) return 0;
	return sizeFromNode(t->left) + sizeFromNode(t->right);
}
template <typename T>
void BinTree<T>::createBinTree(TreeElement<T>*& t, int len) const {
	if (len == 0) {
		t = NULL;
		return;
	}
	t = new TreeElement<T>;
	t->data = len;
	createBinTree(t->left, len / 2);
	createBinTree(t->right, len / 2);
}


template <typename T>
BinTree<T>::BinTree() {
	root = NULL;
}
template <typename T>
BinTree<T>::BinTree(BinTree<T> const& rhs) {
	copyBinTree(rhs);
}
template <typename T>
BinTree<T>& BinTree<T>::operator= (BinTree<T> const& rhs) {
	if (this == &rhs) return *this;
	deleteBinTree(root);
	copyBinTree(rhs);
	return *this;
}
template <typename T>
BinTree<T>::~BinTree() {
	deleteBinTree(root);
}


template <typename T>
BinTree<T> BinTree<T>::leftBinTree() const {
	BinTree<T> temp;
	copy(temp.root, root->left);
	return temp;
}
template <typename T>
BinTree<T> BinTree<T>::rightBinTree() const {
	BinTree<T> temp;
	copy(temp.root, root->right);
	return temp;
}


template <typename T>
T BinTree<T>::getRootData() const {
	return root->data;
}
template <typename T>
TreeElement<T>* BinTree<T>::getRootPointer() {
	return root;
}


template <typename T>
bool BinTree<T>::empty() const {
	if (root == NULL) return true;
	return false;
}
template <typename T>
int BinTree<T>::size() const {
	return sizeFromNode(root);
}
template <typename T>
void BinTree<T>::input(TreeElement<T>*& t, istream& in) {
	T data;
	in >> data;
	t = new TreeElement<T>;
	t->data = data;
	t->left = t->right = NULL;
	char c;
	in >> c;
	if (c == 'y') input(t->left, in);
	in >> c;
	if (c == 'y') input(t->right, in);
}
template <typename T>
void BinTree<T>::print(ostream& out) const {
	printFromNode(root,out);
	out << "\n";
}


template <typename T>
void BinTree<T>::deleteTree() {
	deleteBinTree(root);
}
template <typename T>
void BinTree<T>::create(int len) {
	createBinTree(root, len);
}
template <typename T>
void BinTree<T>::createWithData(T data, BinTree<T> left, BinTree<T> right) {
	root = new TreeElement<T>;
	root->data = data;
	copy(root->left, left.root);
	copy(root->right, right.root);
}


template <typename T>
istream& operator>> (istream& in, BinTree<T>& obj) {
	obj.input(obj.root, in);
	return in;
}
template <typename T>
ostream& operator<< (ostream& out, BinTree<T>& obj) {
	obj.print(out);
	return out;
}
template <typename T>
ifstream& operator>> (ifstream& fin, BinTree<T>& obj) {
	obj.input(obj.root, fin);
	return fin;
}
template <typename T>
ofstream& operator<< (ofstream& fout, BinTree<T>& obj) {
	obj.print(fout);
	return fout;
}
template <typename T>
bool operator< (BinTree<T> const& obj1, BinTree<T> const& obj2) {
	return (obj1.size() < obj2.size());
}


#endif
