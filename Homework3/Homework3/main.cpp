#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include "BinaryOrderTree.h";
#include "AVLTree.h"
#define L 1e6
#define N int(1e3)
#define M 1e5
using namespace std;
bool matrOrientedGraph[N][N], matrUnorientedGraph[N][N];
vector<int> listOrientedGraph[N], listUnorientedGraph[N];
bool used[N];
void BFSMatr () {
	queue <int> BFS;
	int i, j, v;
	for (i = 0; i < N; i++) {
		used[i] = 0;
	}
	for (i = 0; i < N; i++) {
		if (used[i] != 0) continue;
		used[i] = 1;
		BFS.push(i);
		for (;;) {
			v = BFS.front();
			for (j = 0; j < N; j++) {
				if ((matrOrientedGraph[v][j] == 1) && (used[j] == 0)) {
					used[j] = 1;
					BFS.push(j);
				}
			}
			BFS.pop();
			if (BFS.empty() == 1) break;
		}
	}
}
void BFSList() {
	queue <int> BFS;
	int i, j, v;
	for (i = 0; i < N; i++) {
		used[i] = 0;
	}
	for (i = 0; i < N; i++) {
		if (used[i] != 0) continue;
		used[i] = 1;
		BFS.push(i);
		for (;;) {
			v = BFS.front();
			for (j = 0; j < listOrientedGraph[v].size(); j++) {
				if (used[listOrientedGraph[v][j]] == 0) {
					used[listOrientedGraph[v][j]] = 1;
					BFS.push(listOrientedGraph[v][j]);
				}
			}
			BFS.pop();
			if (BFS.empty() == 1) break;
		}
	}
}
void DFSMatr(int v) {
	if (used[v] == 1) return;
	used[v] = 1;
	int i;
	for (i = 0; i < N; i++) {
		if (matrUnorientedGraph[v][i] == 1) DFSMatr(i);
	}
}
void DFSList(int v) {
	if (used[v] == 1) return;
	used[v] = 1;
	int i;
	for (i = 0; i < listUnorientedGraph[v].size(); i++) {
		DFSList(listUnorientedGraph[v][i]);
	}
}
int main() {
	BinOrderTree<int> bit;
	AVLTree<int> avl;
	double beg_time, end_time;
	int i, j, u, v;
	vector <int> nums;
	for (i = 0; i < L; i++) {
		nums.push_back(i);
	}
	random_shuffle(nums.begin(), nums.end());
	beg_time = clock();
	for (i = 0; i < L; i++) {
		bit.addNode(nums[i]);
	}
	end_time = clock();
	cout << "BinaryOrderTree add method for " << L << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < L; i++) {
		bit.deleteNode(nums[i]);
	}
	end_time = clock();
	cout << "BinaryOrderTree delete method for " << L << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	beg_time = clock();
	for (i = 0; i < L; i++) {
		avl.addNode(i);
	}
	end_time = clock();
	cout << "AVLTree insert method for " << L << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < L; i++) {
		avl.deleteNode(i);
	}
	end_time = clock();
	cout << "AVLTree delete method for " << L << " operations: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	nums.clear();
	for (i = 0; i < N*N; i++) {
		nums.push_back(i);
	}
	random_shuffle(nums.begin(), nums.end());
	for (i = 0; i < M; i++) {
		u = nums[i] / N; v = nums[i] % N;
		matrOrientedGraph[u][v] = 1;
		listOrientedGraph[u].push_back(v);
	}
	beg_time = clock();
	BFSMatr();
	end_time = clock();
	cout << "BFS for oriented graph with " << N << " vertices and " << M << " edges with adjacency matrix: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	BFSList();
	end_time = clock();
	cout << "BFS for oriented graph with " << N << " vertices and " << M << " edges with adjacency list: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";

	nums.clear();
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			nums.push_back(i*N + j);
		}
	}
	random_shuffle(nums.begin(), nums.end());
	for (i = 0; i < M; i++) {
		u = nums[i] / N; v = nums[i] % N;
		matrUnorientedGraph[u][v] = matrUnorientedGraph[v][u] = 1;
		listUnorientedGraph[u].push_back(v);
		listUnorientedGraph[v].push_back(u);
	}
	beg_time = clock();
	for (i = 0; i < N; i++) {
		used[i] = 0;
	}
	for (i = 0; i < N; i++) {
		DFSMatr(i);
	}
	end_time = clock();
	cout << "DFS for unoriented graph with " << N << " vertices and " << M << " edges with adjacency matrix: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	beg_time = clock();
	for (i = 0; i < N; i++) {
		used[i] = 0;
	}
	for (i = 0; i < N; i++) {
		DFSList(i);
	}
	end_time = clock();
	cout << "DFS for oriented graph with " << N << " vertices and " << M << " edges with adjacency list: " << (end_time - beg_time) / CLOCKS_PER_SEC << " s.\n";
	system("PAUSE");
	return 0;
}