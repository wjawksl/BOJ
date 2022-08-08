#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
int main()
{
	ll X1, Y1, R1, X2, Y2, R2;

	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;

	ll d = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
	ll r1r2 = (R1 + R2) * (R1 + R2);

	if (d >= r1r2) cout << "NO";
	else cout << "YES";

	return 0;
}