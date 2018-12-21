#include <iostream>
#include <time.h>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CyclicLinkedList.h"
#include "BinaryTree.h"
#define N 1e6
using namespace std;
int main() {
	SList<int> sl;
	DList<int> dl;
	CList<int> cl;
	BinTree<int> bt;
	double beg_time, end_time;
	int i, val;
	beg_time = clock();
	for (i = 0; i < N; i++) {
		sl.insertToEnd(i);
	}
	end_time = clock();
	cout << "SinglyLinkedList insert method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		sl.iterStart();
		sl.deleteElem(sl.iter(), val);
	}
	end_time = clock();
	cout << "SinglyLinkedList delete method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	for (i = 0; i < N; i++) {
		dl.insertToEnd(i);
	}
	end_time = clock();
	cout << "DoublyLinkedList insert method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		dl.iterStart();
		dl.deleteElem(dl.iter(), val);
	}
	end_time = clock();
	cout << "DoublyLinkedList delete method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	for (i = 0; i < N; i++) {
		cl.insertToEnd(i);
	}
	end_time = clock();
	cout << "CyclicLinkedList insert method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		cl.iterStart();
		cl.deleteElem(cl.iter(), val);
	}
	end_time = clock();
	cout << "CyclicLinkedList delete method for " << N << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	bt.create(N);
	end_time = clock();
	cout << "BinaryTree with " << N << " vertices created: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	bt.deleteTree();
	end_time = clock();
	cout << "BinaryTree with " << N << " vertices deleted: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	system("PAUSE");
	return 0;
}