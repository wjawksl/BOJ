#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int wine[10001];
	int dp[10001];

	cin >> n;
	
	wine[0] = 0;
	

	for (int i = 1; i < n+1; i++)
		cin >> wine[i];
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max(max(wine[1] + wine[2], wine[1] + wine[3]), wine[2] + wine[3]);

	for(int i = 4; i < n+1; i++)
	{
		dp[i] = max(max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]), dp[i - 1]);
	}
	cout << dp[n];
	return 0;
}