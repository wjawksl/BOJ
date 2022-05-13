#include<iostream>
#include<algorithm>

using namespace std;
int dp[10];
int ans[10];
int get_ans(int N)
{
	int n = 0;
	bool flag = false;
	while (n < N)
	{
		if (dp[n] == -1)
		{
			if (n < 2)
			{
				dp[n] = n+1;
				continue;
			}
				
			if (n == 2)
			{
				dp[n] = 4;
				continue;
			}
			dp[n] = dp[n - 3] + dp[n - 2] + dp[n - 1];
		}
		n++;
	}
	return dp[n-1];
}
int main()
{
	int T, N;

	cin >> T;
	fill(dp, dp + 10, -1);
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cout << get_ans(N) << "\n";
		
	}
	return 0;
}