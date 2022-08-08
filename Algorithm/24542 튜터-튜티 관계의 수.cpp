#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
ll N, M, u, v, ans = 1, cnt;
vector<vector<int>> edge;
vector<int> visited;

void DFS(int node)
{
	visited[node] = true;
	for (int i = 0; i < edge[node].size(); i++)
	{
		int next = edge[node][i];

		if (!visited[next])
		{
			cnt++;
			DFS(next);
		}
	}
}
int main()
{
	cin >> N >> M;
	edge.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	
	for (int i = 1; i < N + 1; i++)
	{
		
		if (!visited[i])
		{	
			cnt = 1;
			DFS(i);
			cnt = cnt % 1000000007;
			ans = (ans * cnt) % 1000000007;
		}
	}

	cout << ans;
	return 0;
}