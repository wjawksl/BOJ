#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
vector <ll> tree, num;
int N, Q, h = 1;
void update(int idx, ll val)
{
	idx += h;
	tree[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
ll query(int L, int R, int node, int nodeL, int nodeR)
{
	if (L <= nodeL && nodeR <= R) return tree[node];
	else if (nodeR < L || R < nodeL) return 0;

	int mid = (nodeL + nodeR) / 2;

	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main()
{
	FIO;
	ll x, y, a, b;
	cin >> N >> Q;
	while (N > h) h = h * 2;
	tree.resize(2 * h);
	num.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		tree[i + h] = num[i];
	}
	for (int i = 0; i < N; i++)
	{
		update(i, num[i]);
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y >> a >> b;
		if(x > y) swap(x, y);		

		cout << query(x, y, 1, 1, h) << "\n";
		update(a - 1, b);		
	}
	return 0;
}
