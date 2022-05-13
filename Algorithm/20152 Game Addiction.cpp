#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
typedef long long ll;
ll dp[32][32];
int map[32][32];

ll get_course(int H, int N)
{
	map[H][H] = -1;
	dp[H][H] = 1;

	for (int i = H; i <= N; i++)
		for (int j = H; j <= N; j++)
		{
			if (map[i][j] != -1)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
			
	return dp[N][N];
}
int main()
{
	int H, N;
	cin >> H >> N;
	if (H > N)
		swap(H, N);

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (i > j)
				map[i][j] = -1;
			else
				map[i][j] = 0;
			dp[i][j] = 0;
		}
	}
	
	cout << get_course(H+1, N+1);
	return 0;
}