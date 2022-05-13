#include<iostream>
#include<algorithm>
#include<queue>

#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
struct ed {
	int v;
	int p;
	bool enable = true;
};
priority_queue <pii, vector<pii>, greater<pii>> pq;
vector<vector<int>> parent(505);
vector<vector<ed>> edge(505, vector<ed>());
int visited[505];
int dist[505];
int N, M, S, D, U, V, P;
void Find(int node)
{
	if (parent[node].size() == 0) return;
	for (int i = 0; i < parent[node].size(); i++)
	{
		for (int j = 0; j < edge[parent[node][i]].size(); j++)
		{
			if (edge[parent[node][i]][j].v == node)
			{
				edge[parent[node][i]][j].enable = false;				
				break;
			}
		}
		if (visited[parent[node][i]]) continue;
		visited[parent[node][i]] = 1;
		Find(parent[node][i]);
	}
}
int Dijkstra(int start, int dest)
{
	fill(dist, dist + 505, INF);
	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].v;
			int nextCost = edge[cur][i].p;
			bool flag = edge[cur][i].enable;
			if (flag && dist[next] >= dist[cur] + nextCost)
			{
				if (dist[next] > dist[cur] + nextCost)
				{
					parent[next].resize(0);
					dist[next] = dist[cur] + nextCost;
					parent[next].push_back(cur);
					pq.push({ dist[next], next });
				}
				else
				{
					parent[next].push_back(cur);
				}
			}
		}
	}
	return dist[dest];
}
int main()
{
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) break;		
		edge.resize(0); edge.resize(505);
		parent.resize(0); parent.resize(505);
		fill(visited, visited + 505, 0);
		cin >> S >> D;

		for (int i = 0; i < M; i++)
		{
			cin >> U >> V >> P;
			edge[U].push_back({ V,P });
		}
		Dijkstra(S, D);
		Find(D);
		int answer = Dijkstra(S, D);
		if (answer == INF) cout << -1;
		else cout << answer;
		cout << "\n";
	}
	return 0;
}