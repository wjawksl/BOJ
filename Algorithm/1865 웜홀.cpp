#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, int> pii;

vector <vector <pii>> d(505);
int N, M, W;
int S, E, T;
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
				if (dist[next] > dist[i] + nextCost)
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
	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		d.clear();
		d.resize(505);
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			d[S].push_back({ E,T });
			d[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> S >> E >> T;
			d[S].push_back({ E,-T });
		}
		Bellman_Ford(1);

		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}