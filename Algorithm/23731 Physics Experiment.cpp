#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
typedef long long ll;
ll N, answer = 0;
int main()
{
	cin >> N;

	ll i = 10;

	while (i / 2 <= N)
	{		
		ll tmp = N % i;
		if (tmp >= (i / 2))
		{
			N += i - tmp;
		}
		i *= 10;
	}
	cout << N;
	return 0;
}
