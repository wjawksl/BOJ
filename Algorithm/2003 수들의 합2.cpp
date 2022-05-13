#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[10005];
int dp[10005];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int idx = 0;
	int cnt = 0;
	dp[0] = arr[0];
	if (dp[0] == M) cnt++;
	
	for (int i = 1; i < N; i++)
	{		
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] > M)
		{
			while (dp[i] > M)
			{
				dp[i] -= arr[idx++];
			}
		}
		if (dp[i] == M) cnt++;
	}
	cout << cnt;
	return 0;
}