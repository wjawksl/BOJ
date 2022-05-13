#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int visited[10];
vector<int> v;
vector<int> num;
int N, M, check;
void Print()
{
	if (v.size() == M)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(i);
			Print();
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	Print();
	return 0;
}