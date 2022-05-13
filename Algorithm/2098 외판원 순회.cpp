#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 987654321;
int n;
int w[17][17];
int dp[17][1 << 16];

int tsp(int city, int visit)
{
	int res;
	int ret = dp[city][visit];
	if (ret != 0)
	{
		return ret;
	}
	if (visit == ((1 << n) - 1)) {
		if (w[city][0] != 0)
		{
			return w[city][0];
		}
		return inf;
	}
	ret = inf;
	for (int i = 0; i < n; i++)
	{
		if (w[city][i] == 0 || (visit & (1 << i)))
		{
			continue;
		}
		ret = min(ret, w[city][i] + tsp(i, visit | 1 << i));
	}
	dp[city][visit] = ret;

	return ret;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}
	cout << tsp(0, 1);
}