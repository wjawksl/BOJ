#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int A, B, tmp, cnt = 0;
	cin >> A >> B;
	tmp = B;
	while (A < tmp) {
		if (tmp % 2 == 0)
			tmp /= 2;
		else
		{
			if (tmp % 10 == 1)
				tmp /= 10;
			else
				break;
		}
		cnt++;
	}
	if (A == tmp)
		cout << cnt + 1;
	else
		cout << -1;
	return 0;
}