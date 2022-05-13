#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
{
	int stair[302];
	ll dp[302];
	int N;
	cin >> N;
	stair[0] = 0;
	for (int i = 1; i < N+1; i++)
		cin >> stair[i];

	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i < N + 1; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
	}
	cout << dp[N];
	return 0;
}