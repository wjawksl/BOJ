#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
ll dp[95];
ll fibo(int n)
{
	if (n < 2)
	{
		dp[n] = n;
		return dp[n];
	}
	if (dp[n] == -1)
		fibo(n - 2) + fibo(n - 1);

	return dp[n] = dp[n - 2] + dp[n - 1];
}
int main()
{
	int N;

	fill(dp, dp + sizeof(dp) / sizeof(ll), -1);
	cin >> N;

	cout << fibo(N);

	return 0;
}