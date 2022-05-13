#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string S, T;
bool flag = false;
string Recursion(string str)
{
	if (str.size() == S.size() || flag) // S와 길이가 같아졌거나 이미 그 문자열을 만들 수 있다면
	{
		if (str == S)
			flag = true;
		return str;
	}
	if (str.size() > 0)
	{
		if (str[0] == 'A') // 첫 번째 문자가 A인 경우
		{
			if (str.back() == 'A')
			{
				str.pop_back();
				Recursion(str);
				str.push_back('A');
			}
		}
		else // 첫 번째 문자가 B인 경우
		{
			string tmp = str; // B가 추가 됐다고 가정했을 때 (마지막 문자가 A이든 B이든 상관없이)
			reverse(tmp.begin(), tmp.end());
			str = tmp;

			str.pop_back();
			Recursion(str);

			reverse(tmp.begin(), tmp.end());
			str = tmp;
			if (str.back() == 'A') // 마지막 문자가 A인 경우 >> A가 추가 됐다고 가정했을 때 << 첫 번째 조건
			{
				str.pop_back();
				Recursion(str);
				str.push_back('A');
			}
		}
	}
	return str;
}
int main()
{
	cin >> S >> T;
	Recursion(T);
	cout << flag;
	return 0;
}