#ifndef SECOND_TASK_H_
#define SECOND_TASK_H_
#include <iostream>
#include <queue>
#include "first_task.h"

using namespace std;

bool isBipartite(AdjacencyMatrix g, int src)
{
	int v = g.getNumberOfVertices();
	int* color = new int[v];
	for (int i = 0; i < v; i++)
	{
		color[i] = -1;
	}
	color[src] = 1;

	queue<int> q;
	q.push(src);

	int u = q.front();
	q.pop();

	if (g.atPos(u,u) == 1)
		return false;

	for (int i = 0; i < v; i++)
	{
		if (g.atPos(u,u) && color[i] == -1)
		{
			color[i] = 1 - color[u];
			q.push(i);
		}

		else if (g.atPos(u,u) && color[i] == color[u])
			return false;
	}

	return true;
}


#endif
