#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][100001];
int W[101];
int V[101];

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i < N + 1; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < K + 1; j++)
		{
			if (W[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
	return 0;
}