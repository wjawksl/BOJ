#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll arr[100][2];
ll dp[100];
ll pinary_number(int N)
{
	int n = 1;
	while (n <= N)
	{
		if (dp[n] == 0)
		{
			if (n == 1)
			{
				arr[n][1] = 1;
				dp[n] = 1;
				n++;
				continue;
			}
			
			arr[n][0] = arr[n - 1][1] + arr[n - 1][0];
			arr[n][1] = arr[n - 1][0];
			dp[n] = arr[n][0] + arr[n][1];
		}
		n++;
	}
	return dp[N];
}
int main()
{
	int N;
	cin >> N;

	cout << pinary_number(N);
	return 0;
}