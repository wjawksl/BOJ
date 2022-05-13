#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int W[101];
int V[101];
int dp[101][1000001];

int bag[101];
int N, M, A = 0, res = 0;

int main()
{
	cin >> N >> M;
	
	for (int i = 1; i < N + 1; i++)
		cin >> W[i] >> V[i];
	
	for (int i = 1; i < M + 1; i++)
	{
		cin >> bag[i];
		A = max(A, bag[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= A; j++)
		{
			if (j >= W[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	float res = 0;
	int idx = 1;
	for (int i = 1; i < M + 1; i++)
	{
		float now = dp[N][bag[i]] / (bag[i] * 1.0f);
		if (now > res)
		{
			res = now;
			idx = i;
		}
	}
	cout << idx;
	return 0;
}