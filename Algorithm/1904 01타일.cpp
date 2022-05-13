#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
ll dp[1000000];
int main()
{
	
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		if (i < 3)
		{
			dp[i] = i + 1;
			continue;
		}
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N-1];
	return 0;
}