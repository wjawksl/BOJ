#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

vector <int> dist;
const int INF = 1e9;
vector <vector<pii>> node;

vector <int> goParty;
int N, M, X;
int s, d, t;

void dijkstra(int house)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist.clear();
	dist.resize(N + 1, INF);
	dist[house] = 0;
	pq.push(make_pair(0, house));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		for (int i = 0; i < node[cur].size(); i++)
		{
			int next = node[cur][i].first;
			int nextCost = node[cur][i].second;

			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}
int main()
{
	cin >> N >> M >> X;
	node.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> s >> d >> t;
		node[s].push_back(make_pair(d, t));
	}
	goParty.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		dijkstra(i);
		goParty[i] = dist[X];
	}
	dijkstra(X);
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		goParty[i] += dist[i];
		res = max(res, goParty[i]);
	}
	cout << res;
	return 0;
}