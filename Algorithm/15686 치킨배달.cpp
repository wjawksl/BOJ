#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cmath>

#define INF 1e9;
using namespace std;
typedef pair<int, int> pii;
vector<pii> v, cPos,hPos;
int visited[55][55];
int map[55][55];
int N, M, minDist, sum, minSum = INF;
void go()
{
	if (v.size() == M)
	{
		sum = 0;
		for (int i = 0; i < hPos.size(); i++)
		{
			minDist = INF;			
			for (int j = 0; j < v.size(); j++)
			{
				int dist = abs(hPos[i].first - v[j].first) + abs(hPos[i].second - v[j].second);
				minDist = min(minDist, dist);
			}
			sum += minDist;
		}
		minSum = min(minSum, sum);
	}
	for (int i = 0; i < cPos.size(); i++)
	{
		if (!v.empty() && v.back() >= cPos[i]) continue;
		if (visited[cPos[i].first][cPos[i].second] == 0)
		{
			visited[cPos[i].first][cPos[i].second] = 1;
			v.push_back(cPos[i]);
			go();
			visited[cPos[i].first][cPos[i].second] = 0;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) hPos.push_back({ i,j });
			if (map[i][j] == 2) cPos.push_back({ i,j });
		}
	}
	
	go();
	cout << minSum;
	return 0;
}