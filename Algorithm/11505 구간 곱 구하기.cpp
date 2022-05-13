#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
vector<ll> IDT;
ll B = 1;
void Update(ll node, ll val)
{
	ll idx = node + B;
	IDT[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		IDT[idx] = (IDT[idx * 2] * IDT[idx * 2 + 1]) % 1000000007;
	}
}
ll IDTMul(ll L, ll R)
{
	ll res = 1;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) res = (res * IDT[L]) % 1000000007;
		if (R % 2 == 0) res = (res * IDT[R]) % 1000000007;

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return res;
}
int main()
{
	FIO;
	ll N, M, K, a, b, c, num;
	cin >> N >> M >> K;
	IDT.resize(4 * N);
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
			cout << IDTMul(b - 1, c - 1) << "\n";
		}
	}
	return 0;
}