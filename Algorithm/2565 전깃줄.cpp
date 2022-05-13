#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[100];
int main()
{
	vector <pair<int, int>> v;
	int N, n1, n2, _max,dp_max=0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n1 >> n2;
		v.push_back(make_pair(n1, n2));
	}
	sort(v.begin(), v.end());

	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		_max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j].second < v[i].second)
				_max = max(dp[j], _max);
		}
		dp[i] = _max + 1;
		dp_max = max(dp_max, dp[i]);
	}
	cout << v.size() - dp_max;
	return 0;
}