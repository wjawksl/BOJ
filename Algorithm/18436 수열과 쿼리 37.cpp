#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> idxTree;
int B = 1;
void Update(int node, pii val)
{
	int idx = node + B;
	idxTree[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		idxTree[idx].first = idxTree[idx * 2].first + idxTree[idx * 2 + 1].first;
		idxTree[idx].second = idxTree[idx * 2].second + idxTree[idx * 2 + 1].second;
	}
}
ll GetOddSum(ll L, ll R)
{
	ll sum = 0;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) sum += idxTree[L].first;
		if (R % 2 == 0) sum += idxTree[R].first;

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return sum;
}
ll GetevenSum(ll L, ll R)
{
	ll sum = 0;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1) sum += idxTree[L].second;
		if (R % 2 == 0) sum += idxTree[R].second;

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return sum;
}
int main()
{
	FIO;
	ll N, M, a, b, c, num;
	cin >> N;
	idxTree.resize(4 * N);
	while (B < N) B *= 2;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num % 2 == 1)
			Update(i, { 1,0 });
		else 
			Update(i, { 0,1 });
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (c % 2 == 1)
				Update(b - 1, { 1,0 });
			else
				Update(b - 1, { 0,1 });
		}			
		else
		{
			if(a == 2)
				cout << GetevenSum(b - 1, c - 1) << "\n";
			else if (a == 3)
				cout << GetOddSum(b - 1, c - 1) << "\n";
		}
	}
	return 0;
}