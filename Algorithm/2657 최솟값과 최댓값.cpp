#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9 + 1
using namespace std;
typedef long long ll;
vector<ll> IDTMax;
vector<ll> IDTMin;
ll B = 1;
void UpdateMax(ll node, ll val)
{
	ll idx = node + B;
	IDTMax[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		IDTMax[idx] = max(IDTMax[idx * 2], IDTMax[idx * 2 + 1]);
	}
}
ll GetIDTMax(ll L, ll R)
{
	ll res = 0;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) res = max(res, IDTMax[L]);
		if (R % 2 == 0) res = max(res, IDTMax[R]);

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return res;
}
void UpdateMin(ll node, ll val)
{
	ll idx = node + B;
	IDTMin[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		IDTMin[idx] = min(IDTMin[idx * 2], IDTMin[idx * 2 + 1]);
	}
}
ll GetIDTMin(ll L, ll R)
{
	ll res = INF;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) res = min(res, IDTMin[L]);
		if (R % 2 == 0) res = min(res, IDTMin[R]);

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return res;
}
int main()
{
	FIO;
	ll N, M, a, b, num;
	cin >> N >> M;
	IDTMax.resize(4 * N); IDTMin.resize(4 * N, INF);
	while (B < N) B *= 2;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		UpdateMax(i, num);
		UpdateMin(i, num);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << GetIDTMin(a - 1, b - 1) << " " << GetIDTMax(a - 1, b - 1) << "\n";
	}
	return 0;
}