#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int dp[1005][1005];
int arr[1005][1005];
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	swap(str1, str2);
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
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
	int res = dp[str1.size()][str2.size()];
	cout << res << "\n";
	string ans = "";
    if (res > 0) {
        int x = str1.length();
        int y = str2.length();
        
        while (true) {
            if (x == 0 || y == 0) break;
            if (str1[x - 1] == str2[y - 1]) {
                ans += str1[x - 1];
                x--;
                y--;
            }
            else {
                if (dp[x][y] == dp[x - 1][y]) {
                    x--;
                }
                else if (dp[x][y] == dp[x][y - 1]) {
                    y--;
                }
            }
        }
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			cout << ans[i];
		}
    }
	
	return 0;
}