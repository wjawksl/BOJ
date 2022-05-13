#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[100005];
int dp[100005];
bool flag = false;
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int idx = 0;	
	int answer = N;
	dp[0] = arr[0];
	int len = 1;
	if (dp[0] == M)
	{
		cout << len;
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
		len++;
		while (dp[i] >= M)
		{
			answer = min(len, answer);
			flag = true;
			dp[i] -= arr[idx++];
			len--;
		}
	}
	if (flag)
		cout << answer;
	else cout << 0;

	return 0;
}