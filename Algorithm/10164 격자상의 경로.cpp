#include<iostream>
#include<algorithm>

using namespace std;

int get_course(int N, int M)
{
	int dp[16][16];

	fill(&dp[0][0], &dp[15][16], 0);
	dp[0][1] = 1;

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

	return dp[N][M];
}
int main()
{
	int N, M, K;
	int X, Y;
	cin >> N >> M >> K;
	
	if (K == 0)
		cout << get_course(N, M);
	else
	{
		X = 1;
		Y = K;

		while (Y > M)
		{
			Y -= M;
			X++;
		}
		cout << get_course(X, Y) * get_course(N - X + 1, M - Y + 1);
	}
	return 0;
}