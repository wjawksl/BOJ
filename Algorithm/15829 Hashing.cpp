#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

typedef long long ll;
int N;
string str;
ll ans = 0, m = 1;
int main()
{
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		if(i > 0)
			m = (m * 31) % 1234567891;
		ans = (ans + ((str[i] - 'a' + 1) * m)) % 1234567891;
	}
	cout << ans;
	return 0;
}