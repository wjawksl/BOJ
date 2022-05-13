#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int> pos;
vector<int> neg;
int N, M, num;

bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num > 0) pos.push_back(num);
		else neg.push_back(num);
	}
	sort(pos.begin(), pos.end(), comp);
	sort(neg.begin(), neg.end());

	for (int i = 0; i < pos.size(); i += M)
	{
		ans += pos[i];
	}
	for (int i = 0; i < neg.size(); i += M)
	{
		ans += abs(neg[i]);
	}
	ans *= 2;

	if (!pos.empty() && !neg.empty())
	{		
		ans -= max(abs(pos[0]), abs(neg[0]));
	}
	else if (pos.empty())
	{
		ans += neg[0];
	}
	else if (neg.empty())
	{
		ans -= pos[0];
	}

	cout << ans;

	return 0;
}