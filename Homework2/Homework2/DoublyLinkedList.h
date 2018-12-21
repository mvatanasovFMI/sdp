#include "ListStructures.h"

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template <typename T>
class DList : public List<T> {
private:
	ListElement<T>* currEnd;
public:
	DList();
	DList(DList<T>&);
	DList<T>& operator=(DList<T>&);
	~DList();

	virtual void iterStart(ListElement<T>* p = NULL);
	void iterEnd(ListElement<T>* p = NULL);
	virtual ListElement<T>* iter();
	ListElement<T>* iterPrev();

	virtual void insertToEnd(T const&);

	virtual bool deleteElem(ListElement<T>*, T&);
};


template <typename T>
DList<T>::DList() {
	this->begin = this->end = NULL;
}
template <typename T>
DList<T>::DList(DList<T>& rhs) {
	this->copyList(rhs);
}
template <typename T>
DList<T>& DList<T>::operator=(DList<T>& rhs) {
	if (this == &rhs) return *this;
	this->deleteList();
	this->copyList(rhs);
	return *this;
}
template <typename T>
DList<T>::~DList() {
	this->deleteList();
}


template <typename T>
void DList<T>::iterStart(ListElement<T>* p) {
	if (p == NULL) this->curr = this->begin;
	else this->curr = p;
}
template <typename T>
void DList<T>::iterEnd(ListElement<T>* p) {
	if (p == NULL) currEnd = end;
	else currEnd = p;
}
template <typename T>
ListElement<T>* DList<T>::iter() {
	ListElement<T>* temp = this->curr;
	if (this->curr != NULL) this->curr = this->curr->next;
	return temp;
}
template <typename T>
ListElement<T>* DList<T>::iterPrev() {
	ListElement<T>* temp = currEnd;
	if (currEnd != NULL) currEnd = currEnd->prev;
	return temp;
}


template <typename T>
void DList<T>::insertToEnd(T const& data) {
	ListElement<T>* new1 = new ListElement<T>;
	new1->data = data;
	new1->next = NULL;
	new1->prev = this->end;
	if (this->end == NULL) this->begin = this->end = new1;
	else {
		this->end->next = new1;
		this->end = new1;
	}
}


template <typename T>
bool DList<T>::deleteElem(ListElement<T>* p, T& data) {
	if (p == NULL) {
		cerr << "Invalid pointer\n";
		return false;
	}
	data = p->data;
	if (this->begin == this->end) this->begin = this->end = NULL;
	else if (p == this->begin) {
		this->begin = p->next;
		this->begin->prev = NULL;
	}
	else if (p == this->end) {
		this->end = p->prev;
		this->end->next = NULL;
	}
	else {
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	delete p;
	return true;
}


#endif
