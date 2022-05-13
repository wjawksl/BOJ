#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string str;
	int N;

	cin >> N;
	
	for (int a = 0; a < N; a++)
	{
		cin >> str;
		stack <char> st;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				st.push(str[i]);
			else if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push(str[i]);
			}
		}
		if (st.empty())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}