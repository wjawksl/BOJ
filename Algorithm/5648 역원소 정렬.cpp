#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
typedef long long ll;
bool comp(string s1, string s2)
{
	if (s1.size() < s2.size()) return true;
	else if (s1.size() > s2.size()) return false;
	else return s1 < s2;
}
int main()
{
	int N;
	char s[40];
	string str;
	vector <string> v;
	ll tmp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		str = s;
		reverse(str.begin(), str.end());
		int j = 0;
		int cnt = 0;
		while (str[j] == '0')
		{
			cnt++;
			j++;
		}
		str = str.substr(cnt, str.size() - cnt);
		v.push_back(str);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
	{
		printf("%s\n", v[i].c_str());
	}
	return 0;
}