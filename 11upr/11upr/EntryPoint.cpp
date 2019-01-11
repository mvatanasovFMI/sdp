#include <iostream>
#include <vector>
#include <queue>
#include "LinkedList.h"
using namespace std;
const int kMax = 10;

void printGraph(bool graph[][kMax]) {
    for (int i = 0; i < kMax; i++) {
		for (int j = 0; j < kMax; j++) {
			cout << graph[i][j] << " ";
		}
	}
	cout << endl;
}

void transposeGraph(bool graph[][kMax]) {
	bool transposeGraph[kMax][kMax];
	for (int i = 0; i < kMax; i++) {
		for (int j = 0; j < kMax; j++) {
			if (graph[i][j]) { transposeGraph[i][j] = false; }
			else { graph[i][j] = true; }
		}
	}
	printGraph(transposeGraph);
}

bool isBipartiteMatrix(bool graph[][kMax],int start ) {
	
	int set[kMax];
	for (int i = 0; i < kMax; i++) {
		set[i] = -1;
	}
	set[start] = 1;
	queue<int> q;
	q.push(start);

	
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		 
		if (graph[curr][curr]) { return false; }

		
		for (int i = 0; i < kMax; ++i)
		{
			
			if (graph[curr][i] && set[i] == -1)
			{

				set[i] = 1 - set[curr];
				q.push(i);
			}


			else if (graph[curr][i] && set[i] == set[curr])
				
				return false;
		}
	}

	
	return true;
}

LinkedNode<int>* getVertexPtr(int vertex, LinkedList<LinkedList<int>> &graph) {
	graph.iterStart();
	LinkedNode<LinkedList<int>>* listPtr;
	LinkedNode<int>* vertexPtr;
	do {
		listPtr = graph.iter();
		listPtr->data.iterStart();
		vertexPtr = listPtr->data.iter();
	} while (vertexPtr->data != vertex);
	return vertexPtr;
}
bool isBipartite(LinkedList<LinkedList<int>> graph,int start) {

	int size = graph.length();
	int* set = new int[size];
	for (int i = 0; i < size; i++) {
		set[i] = -1;
	}
	set[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		

		LinkedNode<int>* temp = getVertexPtr(curr, graph);
		while (temp) {
			int vertex = temp->data;
            
			if (set[vertex] == -1)
			{

				set[vertex] = 1 - set[curr];
				q.push(vertex);
			}


			else if (set[vertex] == set[curr])

			{
				delete set;
				return false;
			}
			temp = temp->next;
		}
		
		

		
	}

	delete set;
	return true;
}
int main() {
	bool graph[kMax][kMax];
	for (int i = 0; i < kMax; i++) {
		for (int j = 0; j < kMax; j++) {
			graph[i][j] = (bool)(i % 2);
		}
	}
	printGraph(graph);
	transposeGraph(graph);


	cout << isBipartiteMatrix(graph,1);


	return 0;
}