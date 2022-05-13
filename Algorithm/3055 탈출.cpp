#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
char map[51][51];
int visited[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
queue <pii> qu_h;
queue <pii> qu_w;
int R, C;
pii dest;
bool flag = false;
void Hedgehog(int x, int y)
{
	visited[x][y] = 1;

	pii now = qu_h.front();
	qu_h.pop();
	for (int i = 0; i < 4; i++)
	{
		pii next = make_pair(now.first + dx[i], now.second + dy[i]);
		if (next == dest)
		{
			flag = true;
			return;
		}
		if ((0 <= next.first && next.first < R) && (0 <= next.second && next.second < C) && map[next.first][next.second] != 'X')
		{
			if (!visited[next.first][next.second])
			{
				for (int j = 0; j < 4; j++)
				{
					pii check = make_pair(next.first + dx[j], next.second + dy[j]);
					if ((0 <= check.first && check.first < R) && (0 <= check.second && check.second < C))
					{
						if (map[check.first][check.second] == '*')
						{
							break;
						}
					}
					if (j == 3)
					{
						map[next.first][next.second] = 'S';
						visited[next.first][next.second] = 1;
						qu_h.push(next);
					}
				}
			}
		}
	}
}
void Water(int x, int y)
{
	visited[x][y] = 1;

	pii now = qu_w.front();
	qu_w.pop();

	for (int i = 0; i < 4; i++)
	{
		pii next = make_pair(now.first + dx[i], now.second + dy[i]);
		if ((0 <= next.first && next.first < R) && (0 <= next.second && next.second < C) && map[next.first][next.second] != 'X')
		{
			if (!visited[next.first][next.second] && map[next.first][next.second] != 'D')
			{
				map[next.first][next.second] = '*';
				visited[next.first][next.second] = 1;
				qu_w.push(next);
			}
		}
	}
}
int main()
{
	char ch;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S') qu_h.push({ i,j });
			if (map[i][j] == '*') qu_w.push({ i,j });
			if (map[i][j] == 'D') dest = { i,j };
		}
	}
	int layer = 0;
	while (!(qu_h.empty() && qu_w.empty()))
	{
		int quHcnt = qu_h.size();
		int quWcnt = qu_w.size();

		for (int i = 0; i < quHcnt; i++)
		{
			Hedgehog(qu_h.front().first, qu_h.front().second);
		}
		if (flag)
		{
			layer++;
			break;
		}
		for (int i = 0; i < quWcnt; i++)
		{
			Water(qu_w.front().first, qu_w.front().second);
		}
		layer++;
	}
	if (flag)
		cout << layer << "\n";
	else
		cout << "KAKTUS\n";
	return 0;
}