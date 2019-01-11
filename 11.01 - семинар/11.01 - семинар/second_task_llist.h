#ifndef SECOND_TASK_LLIST_H_
#define SECOND_TASK_LLIST_H_
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include "linked_list.h"

using namespace std;

class Graph
{
private:
	LList<LList<int> > g;
public:
	Elem<int>* getVertexPtr(int);

	void addVertex(int);
	void addEdge(int, int);
	void create();
	void display();

};


Elem<int>* Graph::getVertexPtr(int a)
{
	g.IterStart();
	Elem<LList<int>>* list_ptr;
	Elem<int>* vertex_ptr;
	do
	{
		list_ptr = g.Iter();
		list_ptr->data.IterStart();
		vertex_ptr = list_ptr->data.Iter();
	} while (vertex_ptr->data != a);
	return vertex_ptr;
}

void Graph::addVertex(int a)
{
	LList<int> list;
	list.InsertToEnd(a);
	g.InsertToEnd(list);
}

void Graph::addEdge(int a, int b)
{
	Elem<int>* ptr = getVertexPtr(a);
	Elem<int>* newElem;
	while (ptr->next)
	{
		ptr = ptr->next;
	}

	newElem = new Elem<int>;
	newElem->data = b;
	newElem->next = nullptr;
	ptr = newElem;

	//ptr.SetEnd(newElem);
}

void Graph::create()
{
	for (int i = 1; i <= 1000; i++)
	{
		addVertex(i);

		addEdge(i, 2);
		addEdge(i, 12);
		addEdge(i, 112);
		addEdge(i, 1112);
		addEdge(i, 22);
		addEdge(i, 222);
		addEdge(i, 2222);
		addEdge(i, 32);
		addEdge(i, 332);
		addEdge(i, 3332);

	}
}

void Graph::display()
{
	g.IterStart();
	Elem<LList<int>>* currentElementPtr = g.Iter();
	while (currentElementPtr) {
		currentElementPtr->data.Print();
		currentElementPtr = currentElementPtr->next;
	}
	cout << endl;
}

bool member(int& x, LList<int>& l)
{
	l.IterStart();
	Elem<int>* p = l.Iter();
	while (p&&p->data != x)
	{
		p = p->next;
	}
	return p != nullptr;
}



#endif
