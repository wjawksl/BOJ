#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int map[1005][1005];

ll dp[1005][1005];
int N, H, W;
int main()
{
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[0][0] = ll(N - 1);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{			
			if (dp[i][j] % 2 == 1) map[i][j] = map[i][j] == 1 ? 0 : 1;
			if (map[i][j] == 1 && dp[i][j] != 0)
			{				
				if ((0 <= i && i < H) && 0 <= j + 1 && j + 1 < W)
				{
					if (dp[i][j] % 2 == 0)
					{
						dp[i][j + 1] += dp[i][j] / 2L;						
					}						
					else
					{
						dp[i][j + 1] += dp[i][j] / 2L + 1;
					}						
				}
				if ((0 <= i + 1 && i + 1 < H) && 0 <= j && j < W)
				{
					dp[i + 1][j] += dp[i][j] / 2L;
				}
			}
			else if (map[i][j] == 0 && dp[i][j] != 0)
			{
				if ((0 <= i + 1 && i + 1 < H) && 0 <= j && j < W)
				{
					if (dp[i][j] % 2 == 0)
					{
						dp[i + 1][j] += dp[i][j] / 2L;
					}
					else
					{
						dp[i + 1][j] += dp[i][j] / 2L + 1;
					}
				}
				if ((0 <= i && i < H) && 0 <= j + 1 && j + 1 < W)
				{
					dp[i][j + 1] += dp[i][j] / 2L;
				}				
			}			
		}
	}
	cout << map[0][0] << dp[0][0];
	return 0;
}