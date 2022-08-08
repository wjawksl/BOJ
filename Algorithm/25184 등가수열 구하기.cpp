#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> v;
vector<int> visited;
int N, a;

int main()
{
	cin >> N;

	visited.resize(N + 1);
	v.push_back((1 + N + 1) / 2);
	visited[(1 + N + 1) / 2] = true;
	
	a = N / 2;

	while (v.size() != N)
	{
		for (int i = 1; i < N + 1; i++)
		{
			if (!visited[i] && abs(v.back() - i) >= a)
			{
				visited[i] = true;
				v.push_back(i);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}