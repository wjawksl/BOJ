#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
ll arr[1001][1001];
ll dp[1001][1001];

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < M+1; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < M+1; j++)
		{
			if (i == 1)
				dp[i][j] = arr[i][j] + dp[i][j - 1];

			dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	cout << dp[N][M];
	return 0;
}