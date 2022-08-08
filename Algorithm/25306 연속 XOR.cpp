#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll XorSum(ll num)
{
	ll m = num % 4;

	if (m == 0) return num;
	else if (m == 1) return 1;
	else if (m == 2) return num + 1;
	else return 0;
}
int main()
{
	ll A, B;

	cin >> A >> B;

	ll ans = XorSum(A - 1) ^ XorSum(B);
	
	cout << ans;
	return 0;
}