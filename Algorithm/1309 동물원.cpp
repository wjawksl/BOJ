#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int dp[100005];
int main()
{
	int N;
	cin >> N;
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	cout << dp[N];
	return 0;
}