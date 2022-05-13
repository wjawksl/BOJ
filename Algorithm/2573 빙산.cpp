#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> iceberg(305, vector<int>(305));
vector <vector<int>> visited(305, vector<int>(305));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M, num, year = 0, cnt;
bool flag = false;
void BFS(pair<int, int> p)
{
	visited[p.first][p.second] = 1;
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 <= nextdx && nextdx < N) && (0 <= nextdy && nextdy < M))
			{
				if (visited[nextdx][nextdy] == 1) continue;

				if (iceberg[nextdx][nextdy] != 0)
				{
					if (!visited[nextdx][nextdy])
					{
						qu.push(make_pair(nextdx, nextdy));
						visited[nextdx][nextdy] = 1;
					}
				}
				else 
				{
					if(iceberg[now.first][now.second] > 0) 
						iceberg[now.first][now.second]--;
				}
			}
		}
	}
}
int main()
{
	FIO;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> iceberg[i][j];
	}
	while (true)
	{
		fill(visited.begin(), visited.end(), vector<int>(305, 0));
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (iceberg[i][j] != 0 && visited[i][j] == 0)
				{
					qu.push({ i,j });
					BFS({i,j});
					cnt++;
				}
			}
		}
		if (cnt >= 2) break;
		else if (cnt == 0)
		{
			flag = true;
			break;
		}
		year++;
	}

	if (flag) cout << 0;
	else cout << year;

	return 0;
}