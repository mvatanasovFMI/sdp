#ifndef GRAPHS_GRAPHS_GRAPH
#define GRAPHS_GRAPHS_GRAPH

#include <iostream>
#include "linked_list.h"
using namespace std;


template <typename T>
class Graph {
private:
	LList<LList<T>> graph;
public:
	void addPoint(const T&);
	void addRib(const T&, const T&);
	void deletePoint(const T&);
	void deleteRib(const T&, const T&);
	bool isPointInGraph(const T&);
	bool isRibInGraph(const T&, const T&);
	bool empty() const;
	ListElement<T>* getPointPtr(const T&);
	void print();
};

template <typename T>
void Graph<T>::addPoint(const T& a) {
	LList<T> list;
	list.insertToEnd(a);
	graph.insertToEnd(list);
}
template <typename T>
ListElement<T>* Graph<T>::getPointPtr(const T& a) {
	graph.iterStart();
	ListElement<LList<T>>* listPtr;
	ListElement<T>* pointPtr;
	do {
		listPtr = graph.iter();
		listPtr->data.iterStart();
		pointPtr = listPtr->data.iter();
	} while (pointPtr->data != a);
	return pointPtr;
}
template <typename T>
void Graph<T>::addRib(const T& a, const T& b) {
	ListElement<T> * pointPtr = getPointPtr(a), *newElem;
	newElem = new ListElement<T>;
	newElem->data = b;
	newElem->next = pointPtr->next; 
	pointPtr->next = newElem;
}

template <typename T>
void Graph<T>::deletePoint(const T& a) {
	graph.iterStart();
	ListElement<LList<T>>* listPtr = graph.iter(), *tempListPtr;
	while (listPtr) {
		listPtr->data.iterStart();
		ListElement<T>* pointPtr = listPtr->data.iter();
		if (isRibInGraph(pointPtr->data, a)) {
			deleteRib(pointPtr->data, a);
		}
		listPtr = listPtr->next;
	}
	graph.iterStart();
	ListElement<T>* pointPtr;
	do {
		tempListPtr = graph.iter();
		tempListPtr->data.iterStart();
		pointPtr = tempListPtr->data.iter();
	} while (pointPtr->data != a);
	LList<T> x;
	graph.deleteElem(tempListPtr, x);
}

template <typename T>
void Graph<T>::deleteRib(const T& a, const T& b) {
	graph.iterStart();
	ListElement<LList<T>> *listPtr;
	ListElement<T> *pointPtr;
	do {
		listPtr = graph.iter();
		listPtr->data.iterStart();
		pointPtr = listPtr->data.iter();
	} while (pointPtr->data != a);
	pointPtr = pointPtr->next;
	
	while (pointPtr->data != b) {
		pointPtr = pointPtr->next;
	}
	T x;
	listPtr->data.deleteElem(pointPtr, x);
}

template <typename T>
bool Graph<T>::isPointInGraph(const T& a) {
	if (graph.empty()) {
		return false;
	}
	graph.iterStart();
	ListElement<LList<T>> *listPtr = graph.iter();
	ListElement<T> *pointPtr;
	do {
		listPtr->data.iterStart();
		pointPtr = listPtr->data.iter();
		listPtr = listPtr->next;
	} while (pointPtr->data != a && listPtr);
	return pointPtr->data == a;
}

template <typename T>
bool Graph<T>::isRibInGraph(const T& a, const T& b) {
	ListElement<T>* pointPtr = getPointPtr(a);
	pointPtr = pointPtr->next;
	while (pointPtr && pointPtr->data != b) {
		pointPtr = pointPtr->next;
	}
	return pointPtr != NULL;
}
template <typename T>
bool Graph<T>::empty() const {
	return graph.empty();
}

template <typename T>
void Graph<T>::print() {
	graph.iterStart();
	ListElement<LList<T>> *listPtr = graph.iter();
	while (listPtr) {
		listPtr->data.print();
		listPtr = graph.iter();
	}
	cout << endl;
}

#endif