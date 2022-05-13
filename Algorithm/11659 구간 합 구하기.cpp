#include<iostream>
#include<vector>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int dp[100005];
int main()
{
	FIO;
	int N, M, num, a, b;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> num;
		dp[i] = dp[i-1] + num;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}
	return 0;
}