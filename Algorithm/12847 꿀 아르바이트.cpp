#include<iostream>
#include<algorithm>

using namespace std;

long long dp[100000];
int wage[100000];
int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> wage[i];

	dp[0] = wage[0];
	for (int i = 1; i < m; i++)
		dp[i] = dp[i - 1] + wage[i];

	long long _max = dp[m - 1];
	
	for (int i = m; i < n; i++)
	{
		dp[i] = dp[i-1] + wage[i] - wage[i - m];
		_max = max(_max, dp[i]);
	}
	cout << _max;
	return 0;
}