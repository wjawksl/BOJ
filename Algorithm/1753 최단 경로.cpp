#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
vector<vector<pii>> edge;
priority_queue <pii, vector<pii>, greater<pii>> pq;
int visited[20005];
int dist[20005];

void Dijkstra(int start)
{
	dist[start] = 0;
	pq.push({ dist[start], start});
	while (!pq.empty())
	{		
		int now = pq.top().second;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = 1;
		for (int i = 0; i < edge[now].size(); i++)
		{		
			int next = edge[now][i].first;
			int nextCost = edge[now][i].second;
			if (dist[next] > dist[now] + nextCost)
			{				
				dist[next] = dist[now] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main()
{
	FIO;
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	edge.resize(V + 1);
	fill(dist, dist + 20005, INF);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back({ v,w });		
	}
	Dijkstra(K);
	for (int i = 1; i < V + 1; i++)
	{
		if(dist[i] != INF)
			cout << dist[i] << " ";
		else cout << "INF" << " ";
	}
	return 0;
}