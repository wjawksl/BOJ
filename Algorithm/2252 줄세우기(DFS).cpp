#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector <vector <int>> v(32005);
bool visited[32005];
stack <int> st;

void DFS(int n)
{
	visited[n] = true;
	for (int i = 0; i < v[n].size(); i++)
	{
		if (!visited[v[n][i]])
			DFS(v[n][i]);
	}
	st.push(n);
}

int main()
{
	int N, M, A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
			DFS(i);
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	
	return 0;
}