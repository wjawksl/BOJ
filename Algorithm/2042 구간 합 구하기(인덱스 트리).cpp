#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
vector<ll> idxTree;
ll B = 1;
void Update(ll node, ll val)
{
	ll idx = node + B;
	idxTree[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		idxTree[idx] = idxTree[idx * 2] + idxTree[idx * 2 + 1];
	}
}
ll GetSum(ll L, ll R)
{
	ll sum = 0;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) sum += idxTree[L];
		if (R % 2 == 0) sum += idxTree[R];

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return sum;
}
int main()
{
	FIO;
	ll N, M, K, a, b, c, num;
	cin >> N >> M >> K;
	idxTree.resize(4 * N);
	while (B < N) B *= 2;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		Update(i, num);
	}
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			Update(b - 1, c);
		else
		{
			cout << GetSum(b - 1, c - 1) << "\n";
		}
	}
	return 0;
}