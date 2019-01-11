#include <iostream>
#include "first_task.h"
#include "second_task.h"
#include "second_task_llist.h"

using namespace std;

int main()
{
	AdjacencyMatrix g(4);
	g.addEdge(0, 0);
	g.addEdge(1, 2);
	g.addEdge(3, 2);
	g.display();
	g.transponse();
	g.display();
	cout << g.getNumberOfVertices();
	cout << isBipartite(g, 0);

	cout << endl;

	Graph g1;
	g1.addVertex(1);
	g1.addVertex(2);
	g1.addVertex(3);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.display();

	return 0;
}