#include<iostream>
#include<algorithm>
#include<queue>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector <ll> dist;
vector <vector<pii>> edge;
priority_queue <pii, vector<pii>, greater<pii>> pq;
int visited[100005];
int sight[100005];
const ll INF = 1e11;
int N, M, K;
int a, b, t;
void dijkstra()
{
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;

		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].first;
			int nextCost = edge[cur][i].second;

			if (!visited[next] && dist[next] > dist[cur] + nextCost && !sight[next])
			{
				dist[next] = dist[cur] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main()
{
	FIO;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> sight[i];
	}
	sight[N - 1] = 0;
	edge.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> t;
		edge[a].push_back({ b, t });
		edge[b].push_back({ a, t });
	}
	dist.resize(N + 1, INF);
	dist[K] = 0;
	pq.push({ 0, K });
	dijkstra();

	if (dist[N - 1] == INF)
		cout << -1 << "\n";
	else
		cout << dist[N - 1] << "\n";

	return 0;
}