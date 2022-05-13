#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FIO ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef pair<int, int> pii;
int parent[200005];
priority_queue <pair<int, pii>, vector< pair<int, pii>>, greater<pair<int, pii>>> pq;
int N, M, x, y, z;
int find(int node)
{
	if (node == parent[node]) return node;
	else return find(parent[node]);
}
void Union(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);

	if (n1 != n2) parent[n2] = n1;
}
bool isUnion(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);

	if (n1 == n2) return true;
	else return false;
}
int Kruskal()
{
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		int n1 = find(pq.top().second.first);
		int n2 = find(pq.top().second.second);

		if (!isUnion(n1, n2)) Union(n1, n2);
		else res += pq.top().first;

		pq.pop();
	}
	return res;
}
int main()
{
	FIO;
	while (true)
	{
		cin >> M >> N;
		if (M == 0 && N == 0) break;
		for (int i = 0; i < M; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y >> z;
			pq.push({ z, { x,y } });
		}
		cout << Kruskal() << "\n";
	}
	
	return 0;
}