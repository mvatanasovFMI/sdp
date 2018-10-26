#include "stack.h"

void Stack::CopyStack(const Stack& st)
{
	if (st.start) {
		Elem *p = st.start, *q = NULL, *s = NULL;
		start = new Elem;
		assert(start != NULL);
		start->inf = p->inf;
		start->link = q;
		q = start;
		p = p->link;
		while (p) {
			s = new Elem;
			assert(s != NULL);
			s->inf = p->inf;
			q->link = s;
			q = s;
			p = p->link;
		}
		q->link = NULL;
	}
	else start = NULL;

}

void Stack::DelStack()
{
	Elem* ptr;
	while (start) {
		ptr = start;
		start = start->link;
		delete ptr;
	}
}

Stack::Stack()
{
	start = NULL;
}

Stack::Stack(const Stack& st)
{
	CopyStack(st);
}

Stack & Stack::operator=(const Stack& st)
{
	if (this != &st) {
		DelStack();
		CopyStack(st);
	}

	return *this;
}

Stack::~Stack()
{
	DelStack();
}

void Stack::Push(const double& inf)
{
	Elem* ptr = start;
	start = new Elem;
	assert(start != NULL);
	start->inf = inf;
	start->link = ptr;
}

void Stack::Pop(double& num)
{
	if (start) {
		num = start->inf;
		Elem* ptr = start;
		start = start->link;
		delete ptr;
	}
	else {
		cout << "The stack is empty!";
	}
}

double Stack::Top()
{
	if (start) {
		return start->inf;
	}
	else {
		return -1;
	}
}

bool Stack::Empty()
{
	return start == NULL;
}

void Stack::SortStack()
{
	Stack temp_stack;
	while (!Empty()) {
		double temp_elem;
		Pop(temp_elem);
		while (!temp_stack.Empty() && temp_stack.Top() > temp_elem) {
			double temp_inf;
			temp_stack.Pop(temp_inf);
			Push(temp_inf);
		}
		temp_stack.Push(temp_elem);
	}
	CopyStack(temp_stack);
}

void Stack::Print()
{
	double x;
	while (!Empty()) {
		Pop(x);
		cout << x << endl;
	}
}
