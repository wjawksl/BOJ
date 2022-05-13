#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
ll dp[1005][1005];
ll Combination(int n, int k)
{
	if (dp[n][k] != 0) return dp[n][k];
	if (k == 0 || n == k)
	{
		dp[n][k] = 1;
		return 1;
	}
	if (k == 1)
	{
		dp[n][k] = n;
		return n;
	}
	return dp[n][k] = Combination(n - 1, k) + Combination(n - 1, k - 1);
}
int main()
{
	int N, K, T;	
	dp[0][0] = 1;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> K >> N;
		cout << Combination(N, K) << "\n";
	}
	
	return 0;
}