#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<char>> mapp(55, vector<char>(55));
vector <vector<int>> high(55, vector<int>(55));
vector <vector<int>> visited(55, vector<int>(55));
map <int, int> m;
int dx[8] = { 0, 1, 1, 1, 0, -1,-1 ,-1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int N, M, num, total, Min;

int BFS(int x, int y, int val)
{
	Min = 1000001;
	int cnt = 0;
	visited[x][y] = 1;
	qu.push(make_pair(x, y));
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= N) && high[nextdx][nextdy] <= val)
			{
				if (!visited[nextdx][nextdy])
				{
					qu.push(make_pair(nextdx, nextdy));
					visited[nextdx][nextdy] = 1;					
					cnt++;
					Min = min(Min, high[nextdx][nextdy]);
				}
			}			
		}
	}
	return cnt;
}
int main()
{
	int x, y;
	char ch;
	cin >> N;
	
	for (int i = 1; i < N + 1; i++)
	{		 
		for (int j = 1; j < N + 1; j++)
		{
			cin >> ch;
			mapp[i][j] = ch;
			if (mapp[i][j] == 'K')
				total++;
			if (mapp[i][j] == 'P')
			{
				x = i;
				y = j;
			}
		}		
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> high[i][j];			
		}
	}
	int lo = 1, mid, hi = 5;

	while (lo + 1 < hi)
	{
		mid = (lo + hi) / 2;
		int cnt = BFS(x, y, mid);
		if (cnt == total)
		{
			hi = mid;
		}
		else if (cnt < total)
		{
			lo = mid;
		}
	}
	cout << hi - Min;
	return 0;
}