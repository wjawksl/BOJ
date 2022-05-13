#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> axis(105, vector<int>(105));
vector <vector<int>> visited(105, vector<int>(105));
vector <int> domain;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M, K, num;

int BFS(pair<int,int> pos)
{
	int cnt = 1;

	qu.push(pos);
	visited[pos.first][pos.second] = 1;
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 <= nextdx && nextdx < N) && (0 <= nextdy && nextdy < M) && axis[nextdx][nextdy] != -1)
			{
				if (!visited[nextdx][nextdy])
				{
					qu.push(make_pair(nextdx, nextdy));
					visited[nextdx][nextdy] = 1;
					cnt++;
				}
			}
		}
	}

	return cnt;
}
int main()
{
	int ld_xpos, ld_ypos, ru_xpos, ru_ypos;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> ld_xpos >> ld_ypos >> ru_xpos >> ru_ypos;
		for (int i = ld_ypos; i < ru_ypos; i++)
		{
			for (int j = ld_xpos; j < ru_xpos; j++)
				axis[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (axis[i][j] == 0 && visited[i][j] == 0)
				domain.push_back(BFS(make_pair(i,j)));
		}
	}
	sort(domain.begin(), domain.end());
	cout << domain.size() << "\n";
	for (int i = 0; i < domain.size(); i++)
		cout << domain[i] << " ";
	return 0;
}