#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int N, stick, m, cnt;
stack<int> st;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> stick;
		st.push(stick);
	}
	int now;
	while (!st.empty())
	{
		now = st.top();
		st.pop();
		if (now > m)
		{
			m = now;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}