#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	while (str != ".")
	{
		stack <char> st;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push(str[i]);
			}
			else if (str[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					st.push(str[i]);
			}
		}
		if (st.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		getline(cin, str);
	}
	
	return 0;
}