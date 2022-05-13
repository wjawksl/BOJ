#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define MaxNode 100005
#define MaxLev 20
using namespace std;

vector<vector<int>> tree(MaxNode);
int depth[MaxNode];
int dp[MaxNode][MaxLev];
int visited[MaxNode];
int N;
void DFS(int n, int d)
{
	visited[n] = 1;
	depth[n] = d;
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i];
		if (!visited[next])
		{
			dp[next][0] = n;
			DFS(next, d + 1);
		}
	}
}
void MakeDP()
{
	for (int j = 1; j < MaxLev; j++)
	{
		for (int i = 1; i < MaxNode; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}
int LCA(int n1, int n2)
{
	if (depth[n1] > depth[n2])
		swap(n1, n2);

	for (int i = MaxLev - 1; i >= 0; i--)
	{
		if (depth[n1] <= depth[dp[n2][i]])
			n2 = dp[n2][i];
	}
	if (n1 == n2) return n1;
	for (int i = MaxLev - 1; i >= 0; i--)
	{
		if (dp[n1][i] != dp[n2][i])
		{
			n1 = dp[n1][i];
			n2 = dp[n2][i];
		}
	}
	return dp[n1][0];
}
int main()
{
	FIO;
	int N, M, v1, v2;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> v1 >> v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}
	DFS(1, 1);
	MakeDP();
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		cout << LCA(v1, v2) << "\n";
	}
	return 0;
}