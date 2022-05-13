#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

vector <vector <pii>> d(505);
int N, M;
int A, B, C;
const int INF = 987654321;
long long dist[505];
bool flag;
void Bellman_Ford(int start)
{
	flag = false;
	fill(dist, dist + 505, INF);
	dist[start] = 0;

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < d[i].size(); j++)
			{
				int next = d[i][j].first;
				int nextCost = d[i][j].second;
				if (dist[i] != INF && dist[next] > dist[i] + nextCost)
				{
					dist[next] = dist[i] + nextCost;
					if (k == N) flag = true;
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		d[A].push_back({ B,C });
	}
	Bellman_Ford(1);

	if (flag)
		cout << -1;
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] != INF)
				cout << dist[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}
	
	return 0;
}