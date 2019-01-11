#ifndef FIRST_TASK_H_
#define FIRST_TASK_H_
#include <iostream>

using namespace std; 

///Последователно представяне:
class AdjacencyMatrix
{
private:
	int number_of_vertices;
	int** adjacency_matrix;
	bool* visited_vertices;
public:
	AdjacencyMatrix(int);

	void addEdge(int, int);
	void display();

	void transponse();
	
	unsigned int getNumberOfVertices() const;
	unsigned int atPos(int,int) const;
};

unsigned int AdjacencyMatrix::getNumberOfVertices() const
{
	return number_of_vertices;
}

inline unsigned int AdjacencyMatrix::atPos(int i, int j) const
{
	if (i >= number_of_vertices || j >= number_of_vertices || i < 0 || j < 0) return -1;
	return adjacency_matrix[i][j];
}

AdjacencyMatrix::AdjacencyMatrix(int num)
{
	number_of_vertices = num;

	visited_vertices = new bool[number_of_vertices];
	adjacency_matrix = new int*[number_of_vertices];

	for (int i = 0; i < number_of_vertices; i++)
	{
		adjacency_matrix[i] = new int[number_of_vertices];
		visited_vertices[i] = 0;

		for (int j = 0; j < number_of_vertices; j++)
		{
			adjacency_matrix[i][j] = 0;
		}
	}

}

void AdjacencyMatrix::addEdge(int start, int end)
{
	if (start < 0 || end < 0 || start > number_of_vertices || end > number_of_vertices)
	{
		return;
	}
	adjacency_matrix[start ][end ] = 1;
}

void AdjacencyMatrix::display()
{
	cout << "Adjacency matrix: " << endl;
	for (int i = 0; i < number_of_vertices; i++)
	{
		for (int j = 0; j < number_of_vertices; j++)
		{
			cout << adjacency_matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

inline void AdjacencyMatrix::transponse()
{
	AdjacencyMatrix temp(number_of_vertices);
	for (int i = 0; i < number_of_vertices; i++)
	{
		for (int j = 0; j < number_of_vertices; j++)
		{
		if (adjacency_matrix[i][j] == 1)
		{
			temp.addEdge(j, i);
		}
		}
	}
	*this = temp;
}




#endif