#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

vector<vector<pii>> tree;
vector<int> route;
int n, parent, node, level, res, _max, dia;
int visited[10005];

bool comp(int n1, int n2)
{
	return n1 > n2;
}
void GetDiameter(int node, int len)
{
	visited[node] = true;

	for (int i = 0; i < tree[node].size(); i++)
	{
		int next = tree[node][i].first;
		if (!visited[next])
		{
			len += tree[node][i].second;
			GetDiameter(next, len);
			len -= tree[node][i].second;
		}
	}
	_max = max(_max, len);
}
int main()
{
	cin >> n;
	tree.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> parent >> node >> level;
		tree[parent].push_back({ node, level });
	}
	for (int i = 1; i <= n; i++)
	{
		route.resize(0);
		fill(visited, visited + 10005, 0);
		dia = 0;
		for (int j = 0; j < tree[i].size(); j++)
		{
			_max = 0;
			GetDiameter(tree[i][j].first, tree[i][j].second);
			route.push_back(_max);
		}
		sort(route.begin(), route.end(),comp);
		if (route.size() == 1)
			res = max(res, route[0]);
		else if(route.size() > 1)
			res = max(res,route[0] + route[1]);
	}
	cout << res;

	return 0;
}