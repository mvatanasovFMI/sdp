#include <iostream>
#include "graph.h"
#include <queue>

using namespace std;

//Задача 1
int** transpose(int** graph, int vertexes) {
	int** graph_new = new int*[3];
	for (int i = 0; i < vertexes; i++) {
		graph_new[i] = new int[vertexes];
		for (int j = 0; j < 3; j++) {
			graph_new[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (graph[i][j] == 1) {
				graph_new[j][i] = 1;
			}
		}
	}

	return graph_new;
}

//Задача 2
bool bipartiteMatrix(int** graph,int vertexes,int start) {
	int* color = new int[vertexes];
	for (int i = 0; i < vertexes; i++) {
		color[i] = -1;
	}
	color[start] = 1;
	queue<int> queue_vertexes;
	queue_vertexes.push(start);
	while (!queue_vertexes.empty()) {
		int temp = queue_vertexes.front();
		queue_vertexes.pop();
		for (int i = 0; i < vertexes; i++) {
			if (graph[temp][i] == 1 && color[i] == -1) {
				color[i] = 1 - color[temp];
				queue_vertexes.push(i);
			}
			else if (graph[temp][i] == 1 && color[i] == color[temp]) {
				return false;
			}
		} 
	}

	delete[] color;
	return true;
}

bool bipartiteLinked(Graph<int> graph,int vertexes,int start) {
	int* color = new int[vertexes];
	for (int i = 0; i < vertexes; i++) {
		color[i] = -1;
	}

	ListElement<int>* elem_ptr = graph.getPointPtr(start);
	queue<int> queue_vertexes;
	queue_vertexes.push(start);

	while (!queue_vertexes.empty())
	{
		int temp = queue_vertexes.front();
		queue_vertexes.pop();
		ListElement<int>* temp_ptr = graph.getPointPtr(temp);
		temp_ptr = temp_ptr->next;
		while (temp_ptr)
		{
			if (color[temp_ptr->data] == -1) {
				color[temp_ptr->data] = 1-color[temp];
				queue_vertexes.push(temp_ptr->data);
			}
			else if (color[temp_ptr->data] == color[temp]) {
				return false;
			}
			temp_ptr = temp_ptr->next;
		}
	}

	delete[] color;
	return false;
}

//Задача 3
void dfsUtil(LList<LList<int>> graph, int starting_node, bool*& visited) {
	visited[starting_node] = true;
	cout << starting_node << " ";

	graph.iterStart();
	ListElement<LList<int>>* list_elem_ptr;
	ListElement<int>* current_node_list;
	//find linked list of starting node
	do {
		list_elem_ptr = graph.iter();
		list_elem_ptr->data.iterStart();
		current_node_list = list_elem_ptr->data.iter();
	} while (current_node_list->data != starting_node);
	//search linked list of starting node
	while (current_node_list) {
		if (!visited[current_node_list->data]) {
			dfsUtil(graph, current_node_list->data, visited);
		}
		current_node_list = current_node_list->next;
	}
}


void findSCC(LList<LList<int>> graph) {
	int num_nodes = graph.length();
	bool* visited = new bool[num_nodes];
	for (int i = 0; i < num_nodes; i++) {
		visited[i] = false;
	}
	
	graph.iterStart();
	ListElement<LList<int>>* graph_elem=graph.iter();
	ListElement<int>* current_node_list;
	while (graph_elem) {
		graph_elem->data.iterStart();
		current_node_list = graph_elem->data.iter();
		if (visited[current_node_list->data] == false) {
			dfsUtil(graph, current_node_list->data, visited);
			cout << endl;
		}
		graph_elem = graph_elem->next;
	}
	delete[] visited;
}

int main() {
	LList<int> l0;
	l0.insertToEnd(0); l0.insertToEnd(1); 

	LList<int> l1;
	l1.insertToEnd(1);  l0.insertToEnd(2);

	LList<int> l2;
	l2.insertToEnd(2);

	LList<int> l3;
	l3.insertToEnd(3); l3.insertToEnd(4);

	LList<int> l4;
	l4.insertToEnd(4);

	LList<LList<int>> graph;
	graph.insertToEnd(l0); graph.insertToEnd(l1); graph.insertToEnd(l2); graph.insertToEnd(l3); graph.insertToEnd(l4);
	findSCC(graph);
	return 0;
}