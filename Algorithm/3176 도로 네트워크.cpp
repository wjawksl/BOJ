#include<iostream>
#include<vector>
#include<algorithm>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define MAXN 100005
#define INF 1e9
#define MAXL 20

using namespace std;

typedef pair<int, int> pii;
vector<vector<pii>> tree(MAXN + 1);
int depth[MAXN + 1];
int dp[MAXN + 1][MAXL + 1];
int Max[MAXN + 1];
int Min[MAXN + 1];
int visited[MAXN + 1];
int N, M, v1, v2, w;

void DFS(int n, int d)
{
	visited[n] = 1;
	depth[n] = d;
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i].first;
		int nextCost = tree[n][i].second;
		if (!visited[next])
		{
			dp[next][0] = n;
			Max[next] = max(Max[n], nextCost);
			Min[next] = min(Min[n], nextCost);
			DFS(next, d + 1);			
		}
	}
}
void MakeDP()
{
	for (int j = 1; j < MAXL; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			/*if(Max[dp[i][j]] != 0 && Max[dp[i][j - 1]] != 0)
				Max[i] = max(Max[dp[i][j]], Max[dp[i][j - 1]]);
			if (Max[dp[i][j]] != INF && Max[dp[i][j - 1]] != INF)
				Min[i] = min(Min[dp[i][j]], Min[dp[i][j - 1]]);*/
		}
	}
}
pii LCA(int n1, int n2)
{
	if (depth[n1] > depth[n2])
		swap(n1, n2);
	for (int i = MAXL; i >= 0; i--)
	{
		if (depth[n1] <= depth[dp[n2][i]])
			n2 = dp[n2][i];
	}
	//if (n1 == n2) return n1;

	for (int i = MAXL; i >= 0; i--)
	{
		if (dp[n1][i] != dp[n2][i])
		{
			n1 = dp[n1][i];
			n2 = dp[n2][i];
		}
	}
	return { dp[n1][0] , dp[n2][0] };
}
int main()
{
	FIO;		
	cin >> N;
	fill(&Min[0], &Min[MAXN], INF);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> v1 >> v2 >> w;
		tree[v1].push_back({v2, w});
		tree[v2].push_back({ v1,w });
	}
	//¼öÁ¤ÇØ¾ßµÊ
	DFS(1, 1);
	cout << Min[0] << " " << Max[0] << dp[0][0] << "\n";
	MakeDP();
	cout << Min[0] << " " << Max[0] << dp[0][0] << "\n";
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;		
	}
	return 0;
}