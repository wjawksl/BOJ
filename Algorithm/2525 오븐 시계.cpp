#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int h, m, t;

int main()
{
	cin >> h >> m;
	cin >> t;

	m += t;

	while (m >= 60)
	{
		m -= 60;
		h++;
	}
	while (h >= 24)
	{
		h-=24;
	}
	cout << h << " " << m;

	return 0;
}