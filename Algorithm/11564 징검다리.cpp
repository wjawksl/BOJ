#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;

vector <ll> v;
ll N;

void bSearch(ll left, ll right)
{
	ll mid = (left + right) / 2;

	if (left > right)
	{
		cout << mid << "\n";
		return;
	}
		
	if (mid > 2 * N / (mid + 1))
		bSearch(left, mid - 1);
	else
		bSearch(mid + 1, right);
	
}
int main()
{
	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		bSearch(1, N);
	}

	return 0;
}