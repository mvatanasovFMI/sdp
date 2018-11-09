#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int x, y, dist;
};

const int SIZE = 100;
bool matrix[SIZE][SIZE];
bool used[SIZE][SIZE];
int rows, cols;
Position first, last;

void input() {
	cin >> rows >> cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> first.x >> first.y;
	cin >> last.x >> last.y;
	first.dist = 0;
}

bool isValid(Position pos)
{
	return pos.x >= 0 && pos.x < rows && pos.y >= 0 && pos.y < cols && 
		matrix[pos.x][pos.y] && !used[pos.x][pos.y];
}

int findMinLen() {
	if (!matrix[first.x][first.y] || !matrix[last.x][last.y] || (first.x == last.x && first.y == last.y)) {
		return 0;
	}
	queue<Position> q;
	q.push(first);
	int minLen = rows * cols + 1;
	Position newPos;
	int br = 0;
	while (!q.empty()) {
		Position current;
		current = q.front();
		q.pop();
		if (current.x == last.x && current.y == last.y && minLen > current.dist) {
			minLen = current.dist;
		}
		matrix[current.x][current.y] = 0;
		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				if (x != 0 || y != 0) {
					newPos.x = current.x + x;
					newPos.y = current.y + y;
					newPos.dist = current.dist + 1;
					if (isValid(newPos)) {
						used[newPos.x][newPos.y] = 1;
						q.push(newPos);
					}
				}
			}
		}
	}
	if (minLen != rows * cols + 1) {
		return minLen;
	}
	return 0;
}

int main() {	
	input();
	cout << findMinLen() << endl;

	return 0;
}
/*
6 6
1 1 0 0 1 0
0 1 1 0 1 0
1 0 1 0 1 1
0 1 1 0 1 1
1 0 1 1 1 0
1 1 0 0 1 0
0 0
0 4
*/