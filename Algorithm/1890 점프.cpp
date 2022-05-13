#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int arr[101][101];
ll dp[101][101];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cin >> arr[i][j];
	}
	dp[1][1] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (i == N && j == N)
				break;
			if (dp[i][j] != 0 && arr[i][j] + i <= N)
				dp[i + arr[i][j]][j] += dp[i][j];

			if (dp[i][j] != 0 && arr[i][j] + j <= N)
				dp[i][j + arr[i][j]] += dp[i][j];
		}
	}
	cout << dp[N][N];
	return 0;
}