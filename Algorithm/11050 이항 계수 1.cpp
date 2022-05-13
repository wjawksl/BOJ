#include<iostream>
#include<algorithm>

using namespace std;

int dp[15][15];
int Combination(int n, int k)
{
	if (k == 0 || n == k) return 1;
	if (k == 1) return n;
	
	if (dp[n][k] != 0) return dp[n][k];

	return dp[n][k] = Combination(n - 1, k) + Combination(n - 1, k - 1);
}
int main()
{
	int N, K;
	cin >> N >> K;

	dp[0][0] = 1;

	cout << Combination(N, K);
	return 0;
}