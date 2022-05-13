#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef long long ll;
int parent[20005];
ll len[20005];

int find(int node)
{
	if (node == parent[node]) return node;
	int p = find(parent[node]);
	len[node] += len[parent[node]];
	parent[node] = p;
	
	return p;
}
void Union(int u, int v) {
	len[u] = abs(u - v) % 1000;
	parent[u] = v;
}
int main()
{
	FIO;
	int TC, N, i, j;
	char cmd;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++)
	{
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			parent[n] = n;
			len[n] = 0;
		}
		while (true)
		{
			cin >> cmd;
			if (cmd == 'E')
			{
				cin >> i;
				find(i);
				cout << len[i] << "\n";
			}
			else if (cmd == 'I')
			{
				cin >> i >> j;
				Union(i, j);
			}
			else if (cmd == 'O') break;
		}
	}
	return 0;
}