#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> maze(105, vector<int>(105));
vector <vector<int>> visited(105, vector<int>(105));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M, num, cnt;

int BFS()
{
	visited[1][1] = 1;
	qu.push(make_pair(1, 1));
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= M) && maze[nextdx][nextdy] != 0)
			{
				if (!visited[nextdx][nextdy])
				{
					qu.push(make_pair(nextdx, nextdy));
					visited[nextdx][nextdy] = 1;
					maze[nextdx][nextdy] = maze[now.first][now.second] + 1;
				}
			}
		}
	}
	return maze[N][M];
}
int main()
{
	cin >> N >> M;
	string str;

	for (int i = 1; i < N+1; i++)
	{
		cin >> str;
		for (int j = 1; j < M+1; j++)
			maze[i][j] = str[j - 1] - '0';
	}
	cout << BFS();

	return 0;
}