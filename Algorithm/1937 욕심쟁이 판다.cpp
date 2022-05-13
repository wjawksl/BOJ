#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
int map[501][501];
int dp[501][501];
int moveX[4] = { 0, 1, 0, -1 };
int moveY[4] = { 1, 0, -1, 0 };

int dfs(int a, int b)
{
	int c = 0;
	if (dp[a][b] == -1) {
		dp[a][b] = 1;
		for (int i = 0; i < 4; ++i) {
			int x = moveX[i] + a;
			int y = moveY[i] + b;
			if (x >= 0 && y >= 0 && x < n && y < n && map[x][y] > map[a][b]) {
				c = max(dfs(x, y), c);
			}
		}
		dp[a][b] += c;
	}
	return dp[a][b];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cnt = max(cnt, dfs(i, j));
		}
	}
	cout << cnt;
}
