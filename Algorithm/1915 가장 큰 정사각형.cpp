#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[1005][1005];
int dp[1005][1005];

int main()
{
	int n, m, ans = 0;
	string str;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j < str.size() + 1; j++)
		{		
			if (str[j - 1] == '1')
			{
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
				ans = max(ans, dp[i][j]);
			}			
		}
	}	
	cout << ans * ans;
	return 0;
}