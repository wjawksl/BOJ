#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
int parent[1005];
priority_queue <pair<int, pii>, vector< pair<int, pii>>, greater<pair<int, pii>>> pq;
vector <char> v;
int N, M, A, B, C, edge = 0, res = 0;
int find(int node)
{
	if (node == parent[node]) return node;
	else return find(parent[node]);
}
void Union(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);

	if (n1 != n2)
	{
		parent[n2] = n1;
		edge++;
	}
}
bool isUnion(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);

	if (n1 == n2) return true;
	else return false;
}
void Kruskal()
{
	while(!pq.empty())
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
}
int main()
{
	char s;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> s;
		v.push_back(s);
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		if (v[A - 1] == v[B - 1]) continue;
		pq.push({ C, { A, B } });
	}
	Kruskal();
	if (edge == N - 1) cout << res;
	else cout << -1;
	return 0;
}