#include<iostream>
#include<algorithm>

using namespace std;

long long X, Y;

int BSearch(int lo, int hi, long long val)
{
	int mid = (lo + hi) / 2;

	if (lo == hi) return mid;

	long long rate = (Y + mid) * 100 / (X + mid);
	if (rate == val)
	{
		return BSearch(mid + 1, hi, val);
	}
	else
	{
		return BSearch(lo, mid, val);
	}
}
int main()
{
	cin >> X >> Y;
	const long long rate_const = Y * 100 / X;

	int answer = BSearch(1, 1000000000, rate_const);
	long long rate = (Y + answer) * 100 / (X + answer);
	if (rate == rate_const) cout << -1;
	else cout << answer;

	return 0;
}