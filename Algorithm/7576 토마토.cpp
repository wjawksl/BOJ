#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> tomato(1005,vector<int>(1005));
vector <vector<int>> visited(1005, vector<int>(1005));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M, num, cnt;

int BFS()
{
	cnt = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (tomato[i][j] == 1)
			{
				qu.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
	
	int num_const = qu.size() , num = 0;
	while (!qu.empty())
	{
		pair<int,int> now = qu.front();
		qu.pop();
		num++;
		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= M) && tomato[nextdx][nextdy] != -1)
			{
				if (!visited[nextdx][nextdy])
				{
					qu.push(make_pair(nextdx, nextdy));
					visited[nextdx][nextdy] = 1;
				}
			}
		}
		if (num_const == num)
		{
			cnt++;
			num_const = qu.size();
			num = 0;
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (visited[i][j] == 0)
				return -1;
		}
	}
	return cnt - 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
			cin >> tomato[i][j];
	}
	visited = tomato;
	cout << BFS();
	return 0;
}