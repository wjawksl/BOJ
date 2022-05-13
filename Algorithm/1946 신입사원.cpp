#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> pii;
int T, N, s, e;

int main()
{
	FIO;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<pii> v;
		for (int i = 0; i < N; i++)
		{
			cin >> s >> e;
			v.push_back({ s,e });
		}
		sort(v.begin(), v.end());
		int num = v[0].second, cnt = 1;
		for (int i = 1; i < N; i++)
		{
			if (v[i].second < num)
			{
				num = v[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}