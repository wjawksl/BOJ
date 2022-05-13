#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string str;
	stack <char> st;
	int cnt = 0, res = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
			cnt++;
		}
		else if (str[i] == ')')
		{
			if (str[i - 1] == '(')
			{
				cnt--;
				res += cnt;
			}
			else
			{
				cnt--;
				res++;
			}
			st.pop();
		}
	}
	cout << res;
	return 0;
}