#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
ll lcm;
int d, s;
ll M, a, b;
ll pa, pb;

int main()
{
	cin >> M;
	pa = 1; pb = 1; d = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> s;
		
		if (s == 1) d = !d;

		pa = a / a;
		pb = b * pb / a;
		
	}
	cout << d << " " << pb;
	return 0;
}