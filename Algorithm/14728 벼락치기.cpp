#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int K[101];
int S[101];
int dp[101][10001];

int N, T;

int main()
{
	cin >> N >> T;

	for (int i = 1; i < N + 1; i++)
		cin >> K[i] >> S[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j >= K[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][T];
	return 0;
}