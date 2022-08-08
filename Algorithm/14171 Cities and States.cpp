#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<string>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef pair<string, string> pss;
map<pss, int> m;
int N, cnt = 0;
string city, code;
int main()
{
	FIO;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> city >> code;

		string key = city.substr(0, 2);

		if (key == code) continue;
		m[{key, code}]++;
		cnt += m[{code, key}];
	}
	
	cout << cnt;
	return 0;
}