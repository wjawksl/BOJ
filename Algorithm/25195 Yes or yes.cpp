#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> edge;
bool visited[100005];
int N, M, u, v, S, s;
bool flag = false;

void DFS(int node)
{
	if (visited[node]) return;
	visited[node] = true;

	if (edge[node].size() == 0) flag = true;
	for (int i = 0; i < edge[node].size(); i++)
	{
		int next = edge[node][i];
		if (!visited[next]) DFS(next);
	}
}
int main()
{
	cin >> N >> M;

	edge.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		edge[u].push_back(v);
	}
	cin >> S;

	for (int i = 0; i < S; i++)
	{
		cin >> s;
		visited[s] = true;
	}
	DFS(1);

	if (flag) cout << "yes";
	else cout << "Yes";

	return 0;
}