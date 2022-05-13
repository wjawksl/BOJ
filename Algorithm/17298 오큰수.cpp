#include<iostream>
#include<stack>

using namespace std;

int seq[1000000];
int res[1000000];
stack <int> st;

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	st.push(seq[N - 1]);
	res[N - 1] = -1;

	for (int i = N - 2; i >= 0; i--)
	{
		while (st.top() <= seq[i])
		{
			st.pop();
			if (st.empty())
				break;
		}
		if (st.empty())
			res[i] = -1;
		else
			res[i] = st.top();
		st.push(seq[i]);
	}
	for (int i = 0; i < N; i++)
		cout << res[i] << ' ';
	return 0;
}