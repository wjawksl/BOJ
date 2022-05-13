#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp[4005][4005];
int main()
{
	int ans = 0;
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}