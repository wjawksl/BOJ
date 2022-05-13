#include<iostream>
#include<algorithm>
#include<vector>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int parent[500000];
int sizes[500000];
int n, m, cnt = 0, p1, p2;
bool flag = false;

int Find(int n)
{
	if (parent[n] == n) return n;
	else return parent[n] = Find(parent[n]);
}

void UnionBySize(int n1, int n2)
{
	n1 = Find(n1);
	n2 = Find(n2);

	if (n1 != n2)
	{
		if (sizes[n1] < sizes[n2]) swap(n1, n2);
		sizes[n1] += sizes[n2];
		parent[n2] = n1;
	}
	else
	{
		flag = true;
		cout << cnt << "\n";
	}
}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		sizes[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (flag)
			break;
		cin >> p1 >> p2;
		cnt++;
		UnionBySize(p1, p2);
	}
	if (!flag)
		cout << 0;

	return 0;
}