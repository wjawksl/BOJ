#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int N, num, res = 0;
	stack <int> st;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num != 0)
		{
			st.push(num);
			res += num;
		}
		else
		{
			res -= st.top();
			st.pop();
		}
	}
	cout << res;
	return 0;
}