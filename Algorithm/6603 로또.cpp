#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int lotto[50];
vector<int> v;
bool visited[50];
int N;
void go()
{
	if (v.size() == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return; // 탈출!
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!v.empty() && v.back() > lotto[i]) continue; // 조합 처리 
		if (!visited[lotto[i]])
		{
			v.push_back(lotto[i]);
			visited[lotto[i]] = true;
			go();
			v.pop_back();
			visited[lotto[i]] = false;
		}
	}
}
int main()
{
	while (true)
	{
		cin >> N;
		fill(lotto, lotto + 50, 0);
		fill(visited, visited + 50, 0);
		v.resize(0);
		if (N == 0) break;
		for (int i = 1; i < N + 1; i++)
		{
			cin >> lotto[i];
		}
		go();
		cout << "\n";
	}
	return 0;
}