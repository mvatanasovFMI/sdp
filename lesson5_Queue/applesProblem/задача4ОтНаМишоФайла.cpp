#include <iostream>
#include <queue>
using namespace std;

struct Position
{
    int x, y;
};

const int SIZE = 100;
int arr[SIZE][SIZE];
bool used[SIZE][SIZE];
int n, m;

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
    cin >> n >> m;
    queue<Position> q;
    int numberApples = 0;
    int numberRotten = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1) numberApples++;
            if (arr[i][j] == 2)
            {
                numberRotten++;
                numberApples++;
                used[i][j] = 1;
                Position pos;
                pos.x = i;
                pos.y = j;
                q.push(pos);
            }
        }
    }
    queue<Position> tempQ;
    int level = 0;
    while (!q.empty())
    {
        Position currPos = q.front();
        q.pop();
        if (!used[currPos.x + 1][currPos.y] && arr[currPos.x + 1][currPos.y] == 1)
        {
            numberRotten++;
            arr[currPos.x + 1][currPos.y] = 2;
            used[currPos.x + 1][currPos.y] = 1;
            Position newPos;
            newPos.x = currPos.x + 1;
            newPos.y = currPos.y;
            tempQ.push(newPos);
        }
        if (!used[currPos.x - 1][currPos.y] && arr[currPos.x - 1][currPos.y] == 1)
        {
            numberRotten++;
            arr[currPos.x - 1][currPos.y] = 2;
            used[currPos.x - 1][currPos.y] = 1;
            Position newPos;
            newPos.x = currPos.x - 1;
            newPos.y = currPos.y;
            tempQ.push(newPos);
        }
        if (!used[currPos.x][currPos.y + 1] && arr[currPos.x][currPos.y + 1] == 1)
        {
            numberRotten++;
            arr[currPos.x][currPos.y + 1] = 2;
            used[currPos.x][currPos.y + 1] = 1;
            Position newPos;
            newPos.x = currPos.x;
            newPos.y = currPos.y + 1;
            tempQ.push(newPos);
        }
        if (!used[currPos.x][currPos.y - 1] && arr[currPos.x][currPos.y - 1] == 1)
        {
            numberRotten++;
            arr[currPos.x][currPos.y - 1] = 2;
            used[currPos.x][currPos.y - 1] = 1;
            Position newPos;
            newPos.x = currPos.x;
            newPos.y = currPos.y - 1;
            tempQ.push(newPos);
        }
        if (q.empty())
        {
            level++;
            while (!tempQ.empty())
            {
                Position pos = tempQ.front();
                q.push(tempQ.front());
                tempQ.pop();
            }
        }
    }
    if (numberRotten == numberApples)
    {
        cout << "All apples are rotten after " << level << " times\n";
    }
    else
    {
        cout << "Some apples remain fresh\n";
    }
}
/*
3 5
2 1 0 2 1
2 0 1 2 1
1 0 0 2 1

4 5
2 2 1 1 1
2 2 1 1 1
1 1 1 1 1
1 1 1 1 1

*/
