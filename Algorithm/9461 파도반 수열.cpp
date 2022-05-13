#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll dp[100];
ll get_ans(int n)
{
	if (dp[n] == 0)
	{
		if (n < 3)
		{
			dp[n] = 1;
			return dp[n];
		}
		else if (n < 5)
		{
			dp[n] = 2;
			return dp[n];
		}
		dp[n] = get_ans(n - 5) + get_ans(n - 1);
	}
	return dp[n];
}
int main()
{
	int N, T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cout << get_ans(N-1) << "\n";
	}
	return 0;
}