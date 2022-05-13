#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool visited[1005];
vector <vector<int>> graph(20005);

void DFS(int val)
{
	visited[val] = true;
	for (int i = 0; i < graph[val].size(); i++)
	{
		int next = graph[val][i];
		if (!visited[next])
			DFS(next);
	}
}
int main()
{
	int N, M, u, v, cnt = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			cnt++;
		}	
	}
	cout << cnt;
	return 0;
}