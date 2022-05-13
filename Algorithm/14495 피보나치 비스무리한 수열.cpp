#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ll dp[120];
	int N;
	cin >> N;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < N; i++)
		dp[i] = dp[i - 3] + dp[i - 1];

	cout << dp[N - 1];
	return 0;
}