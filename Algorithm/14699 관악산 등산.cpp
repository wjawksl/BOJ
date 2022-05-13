#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> edge;
queue <int> qu;
int high[5005];
int dp[5005];
int visited[5005];

void BFS(int node)
{
	fill(visited, visited + 1005, 0);
	visited[node] = 1;
	
	qu.push(node);
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];
			if (!visited[next])
			{
				visited[next] = 1;				
				qu.push(next);
			}
		}
	}
}
int main()
{
	int N, M, e1, e2;
	cin >> N >> M;
	edge.resize(N + 1);
	for (int i = 1; i < N + 1; i++)
	{
		cin >> high[i];
	}
	for (int i = 1; i < M + 1; i++)
	{
		cin >> e1 >> e2;
		if (high[e1] < high[e2]) swap(e1, e2);
		edge[e2].push_back(e1);
	}

	return 0;
}