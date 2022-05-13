#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
int parent[10005];
priority_queue <pair<int, pii>, vector< pair<int, pii>>, greater<pair<int, pii>>> pq;
vector <pii> edge;
int N, M, A, B, C;
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
	for (int i = 0; i < M; i++)
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		if (!isUnion(x, y))
		{
			Union(x, y);
			res += pq.top().first;
		}
		pq.pop();
	}
	return res;
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		pq.push({ C, { A,B } });
	}
	cout << Kruskal();
	return 0;
}