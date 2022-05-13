#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <vector<int>> v;
vector <vector<int>> dp;
int N;
int triangle(int x, int y)
{
	if (x == N-1)
	{
		dp[x][y] = v[x][y];
		return v[x][y];
	}
	if (dp[x][y] == -1)
	{
		dp[x][y] = max(triangle(x + 1, y), triangle(x + 1, y + 1)) + v[x][y];
	}
	return dp[x][y];
}
int main()
{
	int num;
	vector <int> tmp1;
	vector <int> tmp2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> num;
			tmp1.push_back(num);
			tmp2.push_back(-1);
		}
		v.push_back(tmp1);
		dp.push_back(tmp2);
		tmp1.clear();
		tmp2.clear();
	}
	cout << triangle(0, 0);
	cout << dp[0][0];
	return 0;
}