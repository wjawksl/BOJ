#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int visited[10];
vector<int> v;
vector<int> num;
int N, M, check, input,answer = -100000000, cur;
void Print()
{
	if (v.size() == N)
	{
		cur = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			cur += abs(v[i] - v[i + 1]);
		}
		answer = max(answer, cur);
		return;
	}
	for (int i = 0; i < N; i++)
	{
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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		num.push_back(input);
	}
	Print();
	cout << answer << "\n";
	return 0;
}