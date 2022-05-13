#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> LL(105);
int RR[505];
bool done[505];
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
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		LL[a].push_back(b);
	}

	int cnt = 0;
	for (int i = 1; i < N + 1; i++)
	{
		fill(done, done + 505, false);

		if (dfs(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}