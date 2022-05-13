#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

ll GCD(ll n1, ll n2)
{
	ll tmp;
	while (n2 != 0)
	{
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	return n1;
}
int main()
{
	ll x, y, abs_x, abs_y, gcd, cnt = 0,_max,_min;

	scanf("%lld %lld", &x, &y);
	abs_x = abs(x);
	abs_y = abs(y);
	_max = max(abs_x, abs_y);
	_min = min(abs_x, abs_y);
	gcd = GCD(_max, _min);

	if (gcd == 1 || (_min == 0 && _max == 1)) printf("%d", 1);
	else
	{
		if (_min == 0 && _max == 0) printf("%d", 0);
		else printf("%d", 2);
	}

	return 0;
}