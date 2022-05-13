#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

string str1, str2;
int dp[1005][1005];

int main()
{
	FIO;
	cin >> str1 >> str2;
	swap(str1, str2);
	for (int i = 1; i < str1.size() + 1; i++)
	{
		for (int j = 1; j < str2.size() + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int ans1 = dp[str1.size()][str2.size()];
	int cnt = ans1;
	string ans2 = "";
	int r = str1.size(), c = str2.size();
	while (dp[r][c] != 0)
	{		
		if ((dp[r][c] == dp[r][c - 1]) || (dp[r][c] == dp[r - 1][c]))
		{
			if (dp[r][c] == dp[r][c - 1]) c--;			
			else r--;			
		}
		else
		{
			ans2 += str2[c - 1];
			r--; c--;									
		}
	}
	reverse(ans2.begin(), ans2.end());
	cout << ans1 << "\n" << ans2;
	return 0;
}