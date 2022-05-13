#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
ll N, M, answer;
ll tree[1000005];
ll maxHi;

ll BSearch(int lo, int hi)
{
	ll mid = (lo + hi) / 2;

	if (lo > hi) return mid;

	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		if(tree[i] > mid)
			sum += tree[i] - mid;
	}
	if (sum >= M)
	{
		answer = max(answer, mid);
		return BSearch(mid + 1, hi);
	}
	else return BSearch(lo, mid - 1);	
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		maxHi = max(tree[i], maxHi);
	}
	cout << BSearch(0, maxHi);
	return 0;
}