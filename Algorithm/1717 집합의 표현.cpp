#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int parent[1000005];
int Size[1000005];
int N, M;
int Find(int node)
{
	if (node == parent[node]) return node;
	else return parent[node] = Find(parent[node]);
}
void Union(int a, int b)
{
	int n1 = Find(a);
	int n2 = Find(b);

	if (n1 != n2)
	{
		if (Size[n1] > Size[n2])
		{
			parent[n2] = n1;
			Size[n1] += Size[n2];
		}
		else
		{
			parent[n1] = n2;
			Size[n2] += Size[n1];
		}
	}
}
bool isUnion(int a, int b)
{
	int n1 = Find(a);
	int n2 = Find(b);

	if (n1 != n2) return false;
	else return true;
}
int main()
{
	FIO;
	int cmd, a, b;
	cin >> N >> M;
	for (int i = 0; i < 1000005; i++)
	{
		parent[i] = i;
		Size[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			Union(a, b);
		}
		else if (cmd == 1)
		{
			bool ans = isUnion(a, b);
			if (ans) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}