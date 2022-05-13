#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

int main()
{
	stack <int> st;
	int N, num;
	string cmd;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			st.push(num);
		}
		else if (cmd == "pop")
		{
			if (st.empty())
				cout << -1 << "\n";
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (cmd == "size")
			cout << st.size() << "\n";
		else if (cmd == "empty")
			cout << st.empty() << "\n";
		else if (cmd == "top")
		{
			if (st.empty())
				cout << -1 << "\n";
			else
				cout << st.top() << "\n";
		}
	}
	return 0;
}