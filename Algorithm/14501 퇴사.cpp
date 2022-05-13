#include<iostream>
#include<algorithm>

using namespace std;

int dp[25];
int Ti[25];
int Pi[25];
int N;
int main()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> Ti[i] >> Pi[i];
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (i < 5)
		{
			for (int j = 0; j < i; j++)
			{
				if (j + 1 == Ti[i - j])
					dp[i] = max(dp[i], dp[i - (j + 1)] + Pi[i - j]);
				else
					dp[i] = max(dp[i], dp[i - (j + 1)]);
			}
		}
		else
		{
			for (int j = 0; j < 5; j++)
			{
				if (j + 1 == Ti[i - j])
					dp[i] = max(dp[i], dp[i - (j + 1)] + Pi[i - j]);
				else
					dp[i] = max(dp[i], dp[i - (j + 1)]);
			}
		}
	}

	cout << dp[N];

	return 0;
}