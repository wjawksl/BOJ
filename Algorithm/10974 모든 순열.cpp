#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
bool visited[10];
int N;
void go()
{
	if (v.size() == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return; // Å»Ãâ!
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
		{
			v.push_back(i);
			visited[i] = true;
			go();
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N;
	go();
	return 0;
}