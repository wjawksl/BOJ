#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int dp[50001];
	int N, _min;

	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i < N+1; i++)
	{
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (j == 1)
				_min = dp[i - 1 * 1] + 1;
			else
				_min = min(_min, dp[i - j * j] + 1);
		}
		dp[i] = _min;
	}
	cout << dp[N];
	return 0;
}