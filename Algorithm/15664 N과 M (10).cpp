#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> pii;
map<vector<int>, int> m;
int visited[10005];
vector<int> v;
vector<int> num;
int N, M, check, input;
void Print()
{
	if (v.size() == M && m.count(v) == 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		m.insert({ v, 0 });
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!v.empty() && v.back() > num[i]) continue;
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(num[i]);
			Print();
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		num.push_back(input);
	}
	sort(num.begin(), num.end());
	Print();
	return 0;
}