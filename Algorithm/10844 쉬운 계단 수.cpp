#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll dp[101][10];

int main()
{
	ll sum = 0;
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		if (dp[i][0] != 0)
			dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % 1000000000;
		for (int j = 1; j < 9; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000000;
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % 1000000000;
			}
		}
		if (dp[i][9] != 0)
			dp[i + 1][8] = (dp[i + 1][8] + dp[i][9]) % 1000000000;
	}
	for (int i = 0; i < 10; i++)
		sum += dp[N][i];

	cout << sum % 1000000000;
	return 0;
}