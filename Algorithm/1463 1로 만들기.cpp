#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000000];
int make_number1(int n)
{
	if (dp[n] == 0 && n > 1)
	{
		if (n <= 3)
		{
			dp[n] = 1;
			return dp[n];
		}
		
		if (n % 3 == 0 && n % 2 == 0)
			dp[n] = min(min(make_number1(n - 1), make_number1(n / 2)), make_number1(n / 3)) + 1;
		else if (n % 3 == 0)
			dp[n] = min(make_number1(n - 1), make_number1(n / 3)) + 1;
		else if (n % 2 == 0)
			dp[n] = min(make_number1(n - 1), make_number1(n / 2)) + 1;
		else
			dp[n] = make_number1(n - 1) + 1;
	}
	return dp[n];
}
int main()
{
	int N;
	cin >> N;
	cout << make_number1(N);
	return 0;
}