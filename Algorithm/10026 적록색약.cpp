#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<char>> map_normal(105, vector<char>(105));
vector <vector<char>> map_colorWeak(105, vector<char>(105));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N;

void BFS(pair<int, int> pos, vector <vector<char>> &map, char color)
{
	qu.push(pos);
	map[pos.first][pos.second] = ' ';
	while (!qu.empty())
	{
		pair<int, int> now = qu.front();
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.first + dx[i];
			int nextdy = now.second + dy[i];
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= N) && map[nextdx][nextdy] == color)
			{
				qu.push(make_pair(nextdx, nextdy));
				map[nextdx][nextdy] = ' ';
			}
		}
	}
	
}
int main()
{
	int normal = 0, colorWeek = 0;
	cin >> N;
	string str;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> str;
		for (int j = 1; j < str.length() + 1; j++)
		{
			map_normal[i][j] = str[j - 1];
			if(str[j - 1] == 'R' || str[j - 1] == 'G')
				map_colorWeak[i][j] = 'R';
			else
				map_colorWeak[i][j] = 'B';
		}
			
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (map_normal[i][j] != ' ')
			{
				BFS(make_pair(i, j), map_normal, map_normal[i][j]);
				normal++;
			}
			if (map_colorWeak[i][j] != ' ')
			{
				BFS(make_pair(i, j), map_colorWeak, map_colorWeak[i][j]);
				colorWeek++;
			}
		}
	}
	cout << normal << "\n" << colorWeek;
	
	return 0;
}