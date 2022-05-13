#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, num;
	int arr[100000];
	int dp[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	dp[0] = arr[0];
	int _max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i] + dp[i - 1])
			dp[i] = arr[i] + dp[i - 1];
		else
			dp[i] = arr[i];
		_max = max(_max, dp[i]);
	}
	cout << _max;
	return 0;
}