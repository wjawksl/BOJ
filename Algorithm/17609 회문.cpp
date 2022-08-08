#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool flag;
int N, cnt = 0;
string str;
void CheckPseudoPalindrome(int L, int R)
{
	if (cnt > 1) return;

	if (L > R)
	{
		flag = true;
		return;
	}

	if (str[L] != str[R])
	{
		if (str[L + 1] == str[R])
		{
			L++;
			cnt++;
			CheckPseudoPalindrome(L, R);
			L--;
			cnt--;
		}
		if (str[R - 1] == str[L])
		{
			R--;
			cnt++;
			CheckPseudoPalindrome(L, R);
			R++;
			cnt--;
		}
		if (str[L + 1] != str[R] && str[R - 1] != str[L])
		{
			return;
		}
	}
	else CheckPseudoPalindrome(L + 1, R - 1);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;

		string inv = str;
		reverse(inv.begin(), inv.end());
		if (str == inv)
		{
			cout << 0 << "\n";
		}
		else
		{
			int L = 0, R = str.size() - 1;
			cnt = 0; flag = false;
			CheckPseudoPalindrome(0, str.size() - 1);

			if (flag) cout << 1 << "\n";
			else cout << 2 << "\n";
		}
	}

	return 0;
}