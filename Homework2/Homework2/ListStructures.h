#ifndef LISTSTRUCTURES_H_
#define LISTSTRUCTURES_H_


#include <iostream>
using namespace std;

template <typename T>
struct ListElement {
	T data;
	ListElement<T> *prev, *next;
};

template <typename T>
class List {
protected:
	ListElement<T> *begin, *end;
	ListElement<T> *curr;
	void deleteList();
	void copyList(List<T>&);
public:
	virtual void iterStart(ListElement <T>* p = NULL) = 0;
	virtual ListElement<T>* iter() = 0;

	virtual void insertToEnd(T const&) = 0;
	
	virtual bool deleteElem(ListElement<T>*, T&) = 0;

	void print(ostream&);
	int size();

	template <typename U>
	friend istream& operator>> (istream&, List<U>&);
	template <typename U>
	friend ostream& operator<< (ostream&, List<U>&);
	template <typename U>
	friend ifstream& operator>> (ifstream&, List<U>&);
	template <typename U>
	friend ofstream& operator<< (ofstream&, List<U>&);
	template <typename U>
	friend bool operator< (List<U>&, List<U>&);
};

template <typename T>
void List<T>::deleteList() {
	ListElement<T>* p;
	this->iterStart();
	p = iter();
	for (;;) {
		if (p == NULL) break;
		delete p;
		p = this->iter();
		}
	begin = end = NULL;
}
template <typename T>
void List<T>::copyList(List<T>& rhs) {
	begin = end = NULL;
	if (rhs.end != NULL) {
		ListElement<T>* temp = rhs.curr, *p, *new1;
		rhs.iterStart();
		p = rhs.iter();
		for (;;) {
			if (p == NULL) break;
			insertToEnd(p->data);
			p = rhs.iter();
		}
		rhs.curr = temp;
	}
}


template <typename T>
void List<T>::print(ostream& out) {
	ListElement<T> *temp = curr, *p;
	iterStart();
	p = iter();
	for (;;) {
		if (p == NULL) break;
		out << p->data << " ";
		p = iter();
	}
	out << "\n";
	curr = temp;
}
template <typename T>
int List<T>::size() {
	ListElement<T> *temp = curr, *p;
	int sz = 0;
	iterStart();
	p = iter();
	for (;;) {
		if (p == NULL) break;
		sz++;
		p = iter();
	}
	curr = temp;
	return sz;
}


template <typename T>
istream& operator>> (istream& in, List<T>& obj) {
	int n, i;
	T data;
	in >> n;
	for (i = 0; i < n; i++) {
		in >> data;
		obj.insertToEnd(data);
	}
	return in;
}
template <typename T>
ostream& operator<< (ostream& out, List<T>& obj) {
	obj.print(out);
	return out;
}
template <typename T>
ifstream& operator>> (ifstream& fin, List<T>& obj) {
	int n, i;
	T data;
	fin >> n;
	for (i = 0; i < n; i++) {
		fin >> data;
		obj.insertToEnd(data);
	}
	return fin;
}
template <typename T>
ofstream& operator<< (ofstream& fout, List<T>& obj) {
	obj.print(fout);
	return fout;
}
template <typename T>
bool operator< (List<T>& obj1, List<T>& obj2) {
	return (obj1.size() < obj2.size());
}


#endif
