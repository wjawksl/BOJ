#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

queue <pair<int, int>> qu;
vector <vector<int>> map(30, vector<int>(30));
vector <int> domain;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, K, num;

int BFS(pair<int, int> pos)
{
	int cnt = 1;

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
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= N) && map[nextdx][nextdy] == 1)
			{
				qu.push(make_pair(nextdx, nextdy));
				map[nextdx][nextdy] = 0;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> N;
	string str;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> str;
		for (int j = 1; j < str.length() + 1; j++)
			map[i][j] = str[j - 1] - '0';
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (map[i][j] == 1)
				domain.push_back(BFS(make_pair(i, j)));
		}
	}
		
	sort(domain.begin(), domain.end());

	cout << domain.size() << "\n";
	for (int i = 0; i < domain.size(); i++)
		cout << domain[i] << "\n";

	return 0;
}