#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
	int RGB[1001][3];
	int dp[1001][3];
	int N;
	int R, G, B;
	
	cin >> N;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i < N+1; i++)
	{
		cin >> R >> G >> B;

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
	return 0;
}