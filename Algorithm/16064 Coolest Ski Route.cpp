#include<iostream>
#include<algorithm>

using namespace std;

int N, M, e1, e2, len, res = 0;
int edge[1001][1001];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> e1 >> e2 >> len;
		if (edge[e1][e2] < len)
			edge[e1][e2] = len;
	}

	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (edge[i][j] < edge[i][k] + edge[k][j] && (edge[i][k] != 0 && edge[k][j] != 0))
					edge[i][j] = edge[i][k] + edge[k][j];
			}
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			res = max(res, edge[i][j]);
		}
	}
	cout << res;
	return 0;
}