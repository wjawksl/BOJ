#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

typedef pair<string, string> pss;

vector<pss> v;
int N;
string t1, t2;
pss t;
bool comp(pss a, pss b)
{
	if (a.second < b.second) return true;
	else return false;
}
int main()
{
	cin >> N;

	v.push_back(make_pair( "0950" , "0950" ));

	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;
		v.push_back(make_pair(t1, t2));
	}
	v.push_back(make_pair("2210", "2210"));

	sort(v.begin(), v.end(), comp);
	int b_h, f_h, b_m, f_m, total, total_max = 0;

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].second > v[i + 1].first) continue;

		b_h = stoi(v[i].second.substr(0,2)); f_h = stoi(v[i + 1].first.substr(0, 2));
		b_m = stoi(v[i].second.substr(2, 2)); f_m = stoi(v[i + 1].first.substr(2, 2));

		total = (f_h - b_h) * 60 + f_m - b_m - 20;

		total_max = max(total, total_max);
	}

	cout << total_max;

	return 0;
}