#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;
pii matrix[505];
int dp[505];
int main()
{
	int N, r, c;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> r >> c;
		matrix[i] = { r,c };		
	}
	dp[1] = matrix[1].first * matrix[1].second;
	dp[2] = dp[1] * matrix[2].second;
	for (int i = 3; i < N + 1; i++)
	{
		int temp1 = matrix[i - 2].first * matrix[i - 1].first * matrix[i - 1].second + matrix[i - 2].first * matrix[i].first * matrix[i].second;
		int temp2 = matrix[i - 1].first * matrix[i].first * matrix[i].second + matrix[i - 2].first * matrix[i - 2].second * matrix[i].second;
		dp[i] = dp[i - 3] + min(temp1, temp2);
	}
	cout << dp[N];
	return 0;
}