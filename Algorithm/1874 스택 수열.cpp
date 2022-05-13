#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100000];
stack <int> st;
vector <char> res;

int main()
{
	int N, i = 0;
	bool flag = true;
	cin >> N;

	for (int a = 0; a < N; a++)
		cin >> arr[a];
	
	for (int j = 1; j < N + 1; j++)
	{
		st.push(j);
		res.push_back('+');

		while (st.top() == arr[i])
		{
			st.pop();
			res.push_back('-');
			i++;
			if (st.empty())
				break;
		}
	}
	if (st.empty())
	{
		for (int a = 0; a < res.size(); a++)
			cout << res[a] << "\n";
	}
	else
		cout << "NO";
	return 0;
}