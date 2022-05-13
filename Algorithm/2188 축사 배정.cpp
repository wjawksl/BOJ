#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> LL(205);
int RR[205];
bool done[205];
int N, M, a, b;

bool dfs(int x)
{
	for (int i = 0; i < LL[x].size(); i++)
	{
		int p = LL[x][i];
		if (done[p])
			continue;
		done[p] = true;

		if (RR[p] == 0 || dfs(RR[p]))
		{
			RR[p] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			LL[i].push_back(b);
		}	
	}

	int cnt = 0;
	for (int i = 1; i < N + 1; i++)
	{
		fill(done, done + 205, false);

		if (dfs(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}