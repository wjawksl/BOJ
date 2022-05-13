#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll dp[20005];
ll tmp;

int main()
{
	int N;

	cin >> N;
	dp[0] = 1;
	for (int i = 1; i < N+1; i++)
	{
		tmp = i * dp[i - 1];
		tmp %= 1000000000;
		while (tmp % 10 == 0)
		{
			if (tmp < 10)
				break;
			tmp /= 10;
		}
			
		dp[i] = tmp;
	}
	cout << dp[N] % 10;
	return 0;
}