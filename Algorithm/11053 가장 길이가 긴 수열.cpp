#include<iostream>
#include<algorithm>

using namespace std;

int A[1000];
int dp[1000];

int main()
{
	int N,tmp;
	cin >> N;
	int _max = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> A[i];
		tmp = dp[0];

		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
				tmp = max(tmp, dp[j]);
		}
		dp[i] = tmp + 1;
		_max = max(dp[i], _max);
	}
	cout << _max;
	
	return 0;
}