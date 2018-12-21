#include "ListStructures.h"

#ifndef CYCLICLINKEDLIST_H_
#define CYCLICLINKEDLIST_H_

template <typename T>
class CList : public List<T> {
private:
	ListElement<T>* currEnd;
public:
	CList();
	CList(CList<T>&);
	CList<T>& operator=(CList<T>&);
	~CList();

	virtual void iterStart(ListElement<T>* p = NULL);
	virtual ListElement<T>* iter();

	virtual void insertToEnd(T const&);

	virtual bool deleteElem(ListElement<T>*, T&);
};


template <typename T>
CList<T>::CList() {
	this->end = NULL;
}
template <typename T>
CList<T>::CList(CList<T>& rhs) {
	this->copyList(rhs);
}
template <typename T>
CList<T>& CList<T>::operator=(CList<T>& rhs) {
	if (this == &rhs) return *this;
	this->deleteList();
	this->copyList(rhs);
	return *this;
}
template <typename T>
CList<T>::~CList() {
	this->deleteList();
}


template <typename T>
void CList<T>::iterStart(ListElement<T>* p) {
	if (p == NULL) {
		if (this->end != NULL) this->curr = this->end->next;
		else this->curr = NULL;
	}
	else this->curr = p;
}
template <typename T>
ListElement<T>* CList<T>::iter() {
	ListElement<T>* temp = this->curr;
	if (this->curr == NULL) return temp;
	if (this->curr != this->end) this->curr = this->curr->next;
	else this->curr = NULL;
	return temp;
}


template <typename T>
void CList<T>::insertToEnd(T const& data) {
	ListElement<T>* new1 = new ListElement<T>;
	new1->data = data;
	new1->next = NULL;
	new1->prev = this->end;
	if (this->end == NULL) {
		this->end = new1;
		this->end->next = new1;
	}
	else {
		new1->next = this->end->next;
		this->end->next = new1;
		this->end = new1;
	}
}


template <typename T>
bool CList<T>::deleteElem(ListElement<T>* p, T& data) {
	if (p == NULL) {
		cerr << "Invalid pointer\n";
		return false;
	}
	data = p->data;
	if (this->end == this->end->next) {
		this->begin = this->end = NULL;
		delete p;
		return true;
	}
	ListElement<T>* it = this->end;
	for (;;) {
		if (it->next == p) break;
		it = it->next;
	}
	it->next = p->next;
	if (p == this->end) this->end = it;
	delete p;
	return true;
}


#endif