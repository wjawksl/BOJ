#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;

vector<int> v, num;
int visited[15];
set <string> s;
int N, K;
void go()
{
	if (v.size() == K)
	{
		string str = "";
		for (int i = 0; i < v.size(); i++)
		{
			str += to_string(v[i]);
		}
		s.insert(str);
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			v.push_back(num[i]);
			go();
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> K;
	num.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	go();
	cout << s.size();
	return 0;
}