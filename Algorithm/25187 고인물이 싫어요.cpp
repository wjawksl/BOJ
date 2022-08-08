#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector<vector<int>> edge;
int parent[100005];
int tank[100005];
int Size[100005];
queue<int> qu;

int N, M, Q, u ,v, q;

int Find(int node)
{
	if (node == parent[node]) return node;
	else return parent[node] = Find(parent[node]);
}
void Union(int a, int b)
{
	int n1 = Find(a);
	int n2 = Find(b);

	if (n1 == n2) return;

	if (Size[n1] > Size[n2]) swap(n1, n2);

	parent[n2] = n1;
	Size[n1] += Size[n2];
	tank[n1] += tank[n2];
}
bool isUnion(int a, int b)
{
	int n1 = Find(a);
	int n2 = Find(b);

	if (n1 == n2) return true;
	else return false;
}
int main()
{
	FIO;

	cin >> N >> M >> Q;
	
	for (int i = 1; i < N + 1; i++)
	{
		cin >> tank[i];
		if (tank[i] == 0) tank[i]--;
		parent[i] = i;
		Size[i] = 1;
	}
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		Union(u, v);
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> q;
		if (tank[Find(q)] > 0) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}