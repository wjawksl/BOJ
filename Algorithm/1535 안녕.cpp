#include<iostream>
#include<algorithm>

using namespace std;
int N;
int L[30], J[30], dp[25][101];

int main()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		cin >> L[i];
	for (int i = 1; i < N + 1; i++)
		cin >> J[i];

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			if (L[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
			else
				dp[i][j] = dp[i - 1][j];
		} 
	}
	cout << dp[N][99];
	return 0;
}