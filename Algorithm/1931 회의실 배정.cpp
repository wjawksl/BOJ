#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int N, s, e;

bool comp(pii a, pii b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end(), comp);
	int cnt = 1;
	s = v[0].first; e = v[0].second;
	for (int i = 1; i < N; i++)
	{
		if (v[i].first >= e)
		{
			cnt++;
			s = v[i].first; e = v[i].second;
		}
	}
	cout << cnt;
	return 0;
}