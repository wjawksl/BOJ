#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
vector <pii> dist;
vector <ll> dp(100005);
vector <vector<pii>> edge;
priority_queue <pii, vector<pii>, greater<pii>> pq;
const ll INF = 300000000000;
int N, M, x, y;
int u, v, w, cnt = 0;
void dijkstra()
{
	dist.resize(N + 1, {INF, INF});
	dist[x] = {0,0};
	dp[x] = 1;
	pq.push({ 0, x });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].first;
			int nextCost = edge[cur][i].second;

			if ((dist[next].first == dist[cur].first + 1) && (dist[next].second == dist[cur].second + nextCost))
				dp[next] = (dp[next] + dp[cur]) % (100000009);
			if ((dist[next].first >= dist[cur].first + 1) && (dist[next].second > dist[cur].second + nextCost))
			{
				dp[next] = dp[cur];
				dist[next].first = dist[cur].first + 1;
				dist[next].second = dist[cur].second + nextCost;
				pq.push({ dist[next].first, next });
			}
		}
	}
}
int main()
{
	cin >> N >> M >> x >> y;
	edge.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back({ v, w });
	}
	dijkstra();
	if (dist[y].second == INF || dist[y].first == INF || dp[y] == 0)
		cout << -1;
	else
		cout << dist[y].second << "\n" << dist[y].first << "\n" << dp[y];

	return 0;
}