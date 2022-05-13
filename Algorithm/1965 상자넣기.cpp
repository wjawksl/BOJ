#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001];
int arr[1001];
int main()
{
	int N, res = 0;
	cin >> N;

	for (int i = 1; i < N + 1; i++)
		cin >> arr[i];

	dp[1] = 1;
	for (int i = 2; i < N + 1; i++)
	{
		int _max = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j])
				_max = max(dp[j], _max);
		}
		dp[i] = _max + 1;
		res = max(res, dp[i]);
	}
		
	cout << res;
	return 0;
}