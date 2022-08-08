#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool flag;
int N, cnt = 1;
string str;

int main()
{
	cin >> N;
	cin >> str;

	for (int i = 0; i < N - 1; i++)
	{
		if (str[i] - 1 == str[i + 1] || str[i] + 1 == str[i + 1]) cnt++;
		else cnt = 1;

		if (cnt >= 5) flag = true;
	}
	if (flag) cout << "YES";
	else cout << "NO";
	return 0;
}