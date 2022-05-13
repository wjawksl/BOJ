#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector <vector <int>> v(10005);
vector <int> len(10005);
queue <int> qu;
int T[10005];
int route[10005];

void BFS()
{
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (route[next] < route[now] + T[next])
				route[next] = route[now] + T[next];
			len[next]--;
			if (len[next] == 0)
				qu.push(next);
		}
	}
}

int main()
{
	int N, t, W, node,res=0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> t >> W;
		T[i] = t;
		for (int w = 0; w < W; w++)
		{
			cin >> node;
			v[node].push_back(i);
			len[i]++;
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (len[i] == 0)
		{
			qu.push(i);
			route[i] = T[i];
		}
	}
	
	BFS();
	for (int i = 1; i < N + 1; i++)
		res = max(route[i], res);

	cout << res << "\n";

	return 0;
}