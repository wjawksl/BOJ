#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
typedef struct {
	int x;
	int y;
	bool b;
}Info;
int map[11][21];
int visited[11][21];
int dx[] = { 0,1};
int dy[] = { 1,0};
queue <Info> qu;
int N, M;
pii dest;
int layer = 0;
bool flag = false;
void BFS(int x, int y)
{
	visited[x][y] = 1;

	Info now = qu.front();
	qu.pop();
	for (int i = 0; i < 2; i++)
	{
		int nextX = now.x + dx[i], nextY = now.y + dy[i];		
		if (nextX == N - 1 && nextY == M - 1)
		{
			flag = true;
			return;
		}
		if ((0 <= nextX && nextX < N) && (0 <= nextY && nextY < M))
		{
			if (!visited[nextX][nextY])
			{
				
				if (map[nextX][nextY] == 0) // 절벽(0)을 만났을 때
				{
					if (now.b == false)
					{
						now.b = true;
						visited[nextX][nextY] = 1;
						qu.push({ nextX, nextY, now.b });
					}
				}				
				else if (map[nextX][nextY] > 1) // 주기가 있는 지역(2~20)을 만났을 때
				{
					if (layer % map[nextX][nextY] == 0)
					{
						visited[nextX][nextY] = 1;
						qu.push({ nextX, nextY, now.b });
					}
					else qu.push({ nextX, nextY, now.b });
				}
				else
				{
					visited[nextX][nextY] = 1;
					qu.push({ nextX, nextY, now.b });
				}			
			}
		}
	}
}
int main()
{
	char ch;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];			
		}
	}
	qu.push({ 0,0,false });
	while (!qu.empty())
	{
		int quSize = qu.size();
		layer++;
		for (int i = 0; i < quSize; i++)
		{
			BFS(qu.front().x, qu.front().y);
		}
		if (flag)
		{
			cout << layer;
			break;
		}		
	}	
	return 0;
}