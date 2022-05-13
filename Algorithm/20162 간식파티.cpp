#include<iostream>
#include<algorithm>

using namespace std;

int snack[1005];
int dp[1005];
int main()
{
	int N, score, _max, res = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> snack[i];

	dp[0] = snack[0];

	for (int i = 1; i < N; i++)
	{
		_max = 0;
		for (int j = 0; j < i; j++)
		{
			if (snack[j] < snack[i])
				_max = max(dp[j], _max);
		}
		dp[i] = _max + snack[i];
		res = max(dp[i], res);
	}
	cout << res;
	return 0;
}