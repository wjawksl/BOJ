#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ll dp[1001];
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < N + 1; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[N];
	return 0;
}