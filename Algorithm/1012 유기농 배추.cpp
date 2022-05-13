#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> map(55, vector<int>(55));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int M, N, K;

void BFS(pair<int, int> pos)
{
	qu.push(pos);
	map[pos.first][pos.second] = 0;
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 <= nextdx && nextdx < N) && (0 <= nextdy && nextdy < M) && map[nextdx][nextdy] == 1)
			{
				qu.push(make_pair(nextdx, nextdy));
				map[nextdx][nextdy] = 0;
			}
		}
	}
}
int main()
{
	int T, xpos, ypos;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> ypos >> xpos;
			map[xpos][ypos] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j])
				{
					BFS(make_pair(i, j));
					cnt++;
				}
					
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}