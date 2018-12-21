#include "ListStructures.h"

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

template <typename T>
class SList : public List<T> {
public:
	SList();
	SList(SList<T>&);
	SList<T>& operator=(SList<T>&);
	~SList();

	virtual void iterStart(ListElement<T>* p = NULL);
	virtual ListElement<T>* iter();

	virtual void insertToEnd(T const&);
	virtual void insertAfter(ListElement<T>*, T const&);
	virtual void insertBefore(ListElement<T>*, T const&);

	virtual bool deleteAfter(ListElement<T>*, T&);
	virtual bool deleteBefore(ListElement<T>*, T&);
	virtual bool deleteElem(ListElement<T>*, T&);
};


template <typename T>
SList<T>::SList() {
	this->begin = this->end = NULL;
}
template <typename T>
SList<T>::SList(SList<T>& rhs) {
	this->copyList(rhs);
}
template <typename T>
SList<T>& SList<T>::operator=(SList<T>& rhs) {
	if (this == &rhs) return *this;
	this->deleteList();
	this->copyList(rhs);
	return *this;
}
template <typename T>
SList<T>::~SList() {
	this->deleteList();
}


template <typename T>
void SList<T>::iterStart(ListElement<T>* p) {
	if (p == NULL) this->curr = this->begin;
	else this->curr = p;
}
template <typename T>
ListElement<T>* SList<T>::iter() {
	ListElement<T>* temp = this->curr;
	if (this->curr != NULL) this->curr = this->curr->next;
	return temp;
}


template <typename T>
void SList<T>::insertToEnd(T const& data) {
	ListElement<T>* new1 = new ListElement<T>;
	new1->data = data;
	new1->next = new1->prev = NULL;
	if (this->end == NULL) this->begin = this->end = new1;
	else {
		this->end->next = new1;
		this->end = new1;
	}
}
template <typename T>
void SList<T>::insertAfter(ListElement<T>* p, T const& data) {
	if (p == NULL) {
		cerr << "Invalid pointer!\n";
		return;
	}
	ListElement<T>* new1 = new ListElement<T>;
	new1->data = data;
	new1->next = p->next;
	new1->prev = NULL;
	if (p == this->end) this->end = new1;
	p->next = new1;
}
template <typename T>
void SList<T>::insertBefore(ListElement<T>* p, T const& data) {
	if (p == NULL) {
		cerr << "Invalid pointer!\n";
		return;
	}
	if (p == this->begin) {
		ListElement<T>* new1 = new ListElement<T>;
		new1->data = data;
		new1->next = new1->prev = NULL;
		new1->next = this->begin;
		this->begin = new1;
		return;
	}
	ListElement<T>* it = this->begin;
	for (;;) {
		if (it->next == p) break;
		it = it->next;
	}
	insertAfter(it, data);
}


template <typename T>
bool SList<T>::deleteAfter(ListElement<T>* p, T& data) {
	if ((p == NULL) || (p->next == NULL)) {
		cerr << "Invalid pointer!\n";
		return false;
	}
	ListElement<T>* temp = p->next;
	data = temp->data;
	if (temp == this->end) this->end = p;
	p->next = temp->next;
	delete temp;
	return true;
}
template <typename T>
bool SList<T>::deleteBefore(ListElement<T>* p, T& data) {
	if ((p == NULL) || (p == this->begin)) {
		cerr << "Invalid pointer\n";
		return false;
	}
	ListElement<T>* it = this->begin;
	for (;;) {
		if (it->next == p) break;
		it = it->next;
	}
	deleteElem(it, data);
	return true;
}
template <typename T>
bool SList<T>::deleteElem(ListElement<T>* p, T& data) {
	if (p == NULL) {
		cerr << "Invalid pointer\n";
		return false;
	}
	if (p == this->begin) {
		data = p->data;
		if (this->begin == this->end) this->begin = this->end = NULL;
		else this->begin = p->next;
		delete p;
		return true;
	}
	ListElement<T>* it = this->begin;
	for (;;) {
		if (it->next == p) break;
		it = it->next;
	}
	deleteAfter(it, data);
	return true;
}


#endif
