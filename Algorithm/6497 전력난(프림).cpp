#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef pair<int, int> pii;
bool visited[10005];
priority_queue <pii, vector <pii>, greater<pii>> pq;
vector <vector<pii>> edge;
int m, n, x, y, z;
int Prim(int start)
{
	int res = 0;
	visited[start] = true;
	for (int i = 0; i < edge[start].size(); i++)
	{
		pq.push({edge[start][i].second, edge[start][i].first});
	}
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (!visited[node])
		{
			visited[node] = true;
			res += cost;
			for (int i = 0; i < edge[node].size(); i++)
			{
				if (!visited[edge[node][i].first])
					pq.push({ edge[node][i].second, edge[node][i].first});
			}
		}
	}
	return res;
}
int main()
{
	
	FIO;
	while (true)
	{
		int total = 0;
		fill(visited, visited + 10005, 0);

		cin >> m >> n;
		if (m == 0 && n == 0) break;
		edge.clear();
		edge.resize(m + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> z;
			edge[x].push_back({ y,z });
			edge[y].push_back({ x,z });
			total += z;
		}
		cout << total - Prim(1) << "\n";
	}
	
	return 0;
}