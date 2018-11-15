// Maze.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <stack>
#include <set>

using namespace std;

bool left(int row, int col);
bool right(int row, int col);
bool top(int row, int col);
bool bot(int row, int col);
bool move(int row, int col);
void display();
pair<int, int> start;
pair<int, int> endPos;
stack<pair<int, int>> path;
set<pair<int, int>> visited;
int rows;
int cols;
bool **mat;
void initMatrix(int rows, int cols) {
    mat = new bool*[rows];
    for (int row = 0; row < rows; row++) {
        mat[row] = new bool[cols];
        for (int col = 0; col < cols; col++) {
            mat[row][col] = 1;
        }
    }
}
void initRandom(int k) {
    for (int i = 0; i < k; i++) {
        int randRow = rand() % rows;
        int randCol = rand() % cols;
        if(mat[randRow][randCol] == 1) {
            mat[randRow][randCol] = 0;
        }
        else {
            i--;
        }
    }
}
bool isValidPos(int row, int col) {
    pair<int, int> pos(row,col);
    const bool isVisited = visited.find(pos) != visited.end();
    return (row >= 0) && (row < rows) &&
        (col >= 0) && (col < cols) && !isVisited;
}
bool left(int row, int col) {
    col--;
    return move(row,col);
}
bool right(int row, int col) {
    col++;
    return move(row,col);
}
bool top(int row, int col) {
    row++;
    return move(row,col);
}
bool bot(int row, int col) {
    row--;
    return move(row,col);
}
bool move(int row, int col) {
    if(isValidPos(row, col)) {
        pair<int, int> currentPosition(row,col);
        path.push(currentPosition);
        visited.insert(currentPosition);
        
        if(currentPosition == endPos) {
            return true;
        }
        
        if(left(row,col) || right(row,col) || top(row,col) || bot(row,col)) {
            return true;
        }
        else {
            path.pop();
            return false;
        }
    }
    else {
        return false;
    }
}
void printPath() {
    while(!path.empty()) {
        pair<int, int> top = path.top();
        path.pop();
        cout<<"("<<top.first << ":"<<top.second<<")"<<endl;
    }
}
void display()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
//    srand (time(NULL));
    int n = 5;
    int k = 9;
//    cin>>n;
    rows = n;
    cols = n;
//    cin>>k;
    initMatrix(rows, cols);
    initRandom(k);
    display();
    
    start.first = 2;
    start.second = 2;
    endPos.first = 6;
    endPos.second = 5;
    
    if(move(start.first,start.second)) {
        printPath();
    }
    
    system("pause");
    
    return 0;
}
