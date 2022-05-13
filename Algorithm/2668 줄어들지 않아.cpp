#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
ll res[66][10];
ll dp[66][10];
int main()
{
	int N, T;
	cin >> T;
	for (int j = 0; j < 10; j++)
	{
		res[1][j] = 1;
		res[2][j] = 10 - j;
		dp[2][j] = 1;
	}
	for (int i = 3; i < 65; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
				res[i][j] = 10;
			}
			else
			{
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
				res[i][j] = dp[i][j] * (10 - j);
			}
		}
	}
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		ll sum = 0;
		for (int i = 0; i < 10; i++)
			sum += res[N][i];
		cout << sum << "\n";
	}
	
	return 0;
}