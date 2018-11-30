#include <bits/stdc++.h>

using namespace std;


int getRegion(vector<vector<int>> &a, int i, int j, int n, int m) {

	if (i >= n || i<0 || j >= m || j < 0) return 0;
	if (a[i][j] == 0) return 0;

	int count = a[i][j]--;
	count += getRegion(a, i + 1, j + 1, n, m);
	count += getRegion(a, i - 1, j - 1, n, m);
	count += getRegion(a, i - 1, j, n, m);
	count += getRegion(a, i + 1, j, n, m);
	count += getRegion(a, i, j - 1, n, m);
	count += getRegion(a, i, j + 1, n, m);
	count += getRegion(a, i - 1, j + 1, n, m);
	count += getRegion(a, i + 1, j - 1, n, m);

	return count;
}

int dfs(vector<vector<int>> a, int n, int m) {
	int res = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				res = max(res, getRegion(a, i, j, n, m));
			}
		}
	}
	return res;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	return dfs(grid, n, m);
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> grid(n);
	for (int i = 0; i < n; i++) {
		grid[i].resize(m);

		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int res = maxRegion(grid);

	fout << res << "\n";

	fout.close();

	return 0;
}