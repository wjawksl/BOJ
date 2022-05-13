#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9
using namespace std;

struct Pos {
	int x;
	int y;
	bool chance;
};
typedef pair<int, int> pii;
vector<vector<pii>> edge;
vector<int> level;
queue<Pos> qu;
int visited[105][105];
int arm[105][105];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M, l, answer = INF, L, R, mid;

bool CheckRange(int x, int y)
{
	return (0 <= x && x <= N - 1) && (0 <= y && y <= M - 1);
}
void BFS(int x, int y)
{
	fill(&visited[0][0], &visited[104][105], 0);
	visited[x][y] = 1;
	if (level[mid] < arm[x][y]) return;
	qu.push({ x,y, false });
	while (!qu.empty())
	{
		Pos now = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = now.x + dx[i], nextY = now.y + dy[i];
			if (CheckRange(nextX, nextY) && !visited[nextX][nextY])
			{		
				if (level[mid] < arm[nextX][nextY])
				{
					if (now.chance) continue;
					else
					{
						if (CheckRange(nextX + dx[i], nextY + dy[i]) && !visited[nextX + dx[i]][nextY + dy[i]] && level[mid] >= arm[nextX + dx[i]][nextY + dy[i]])
						{
							visited[nextX + dx[i]][nextY + dy[i]] = 1;
							qu.push({ nextX + dx[i], nextY + dy[i], 1 });
						}
					}
				}
				else
				{
					visited[nextX][nextY] = 1;
					qu.push({ nextX, nextY, now.chance });
				}
			}
		}
	}
}
int main()
{
	FIO;
	vector<int> tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arm[i][j];
			tmp.push_back(arm[i][j]);
		}
	}
	sort(tmp.begin(), tmp.end());
	level.push_back(tmp[0]);
	for (int i = 1; i < tmp.size(); i++)
	{
		if(tmp[i] != level.back())
			level.push_back(tmp[i]);
	}	
	L = 0; R = level.size() - 1;
	while (L < R)
	{		
		mid = (L + R) / 2;
		BFS(0, 0);
		if (visited[N - 1][M - 1])
		{			
			R = mid;
		}
		else L = mid + 1;
	}
	cout << level[R];
	return 0;
}