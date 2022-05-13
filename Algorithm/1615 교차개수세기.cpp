#include<iostream>
#include<vector>
#include<algorithm>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<ll> idxTree;
vector <pii> v;
int B = 1;

void Update(int node, int val)
{
	int idx = node + B - 1;
	idxTree[idx] += val;
	while (idx > 1)
	{
		idx /= 2;
		idxTree[idx] = idxTree[idx * 2] + idxTree[idx * 2 + 1];
	}
}
ll GetSum(int L, int R)
{
	L += B - 1; R += B - 1;
	ll sum = 0;
	while (L <= R)
	{
		if (L % 2 == 1) sum += idxTree[L];
		if (R % 2 == 0) sum += idxTree[R];

		L = (L + 1) / 2; R = (R - 1) / 2;
	}
	return sum;
}
int main()
{
	FIO;
	int N, M, num, a, b;
	cin >> N >> M;
	while (B < N) B *= 2;
	idxTree.resize(4 * N);
	for (int i = 1; i < M + 1; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}	
	sort(v.begin(), v.end());

	ll res = 0;
	while (v.size() != 0)
	{
		int Y = v.back().second;
		res += GetSum(1, Y - 1);
		Update(Y, 1);
		v.pop_back();
	}

	cout << res;
	return 0;
}