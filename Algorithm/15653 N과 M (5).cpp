#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int visited[10005];
vector<int> v;
vector<int> num;
int N, M, check, input;
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
	for (int i = 0; i < N; i++)
	{
		if (!visited[num[i]])
		{
			visited[num[i]] = 1;
			v.push_back(num[i]);
			Print();
			visited[num[i]] = 0;
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