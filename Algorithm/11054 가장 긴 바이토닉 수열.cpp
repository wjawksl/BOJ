#include<iostream>
#include<algorithm>

using namespace std;

int seq[1000];
int dp1[1000];
int dp2[1000];

int main()
{
	int N, _max;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	
	dp1[0] = 1;
	for (int i = 1; i < N; i++)
	{
		_max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (seq[j] < seq[i])
				_max = max(dp1[j], _max);
		}
		dp1[i] = _max + 1;
	}

	dp2[N-1] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		_max = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (seq[j] < seq[i])
				_max = max(dp2[j], _max);
		}
		dp2[i] = _max + 1;
	}

	_max = 0;
	for (int i = 0; i < N; i++)
		_max = max(_max, dp1[i] + dp2[i] - 1);

	cout << _max;
	return 0;
}