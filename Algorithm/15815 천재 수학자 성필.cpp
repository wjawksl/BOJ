#include<iostream>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string str;
	stack <int> st;
	int num1, num2, res = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (0 <= str[i] - '0' && str[i] - '0' <= 9)
			st.push(str[i] - '0');
		else
		{
			num2 = st.top();
			st.pop();
			num1 = st.top();
			st.pop();
			switch (str[i])
			{
			case '+':
				res = num1 + num2;
				break;
			case '-':
				res = num1 - num2;
				break;
			case '*':
				res = num1 * num2;
				break;
			case '/':
				res = num1 / num2;
				break;
			default:
				break;
			}
			st.push(res);
		}
	}
	cout << st.top();
	return 0;
}