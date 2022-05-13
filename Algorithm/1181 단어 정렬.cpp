#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
bool comp(string s1, string s2)
{
	if (s1.size() < s2.size()) return true;
	else if (s1.size() > s2.size()) return false;
	else return s1 < s2;
}

int main()
{
	vector <string> v;
	int N;
	char s[55];
	string str;
	bool flag;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		flag = true;
		scanf("%s", s);
		str = s;
		v.push_back(str);
	}
	
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			printf("%s\n", v[i].c_str());
		}
		else
		{
			if (v[i - 1].compare(v[i])) printf("%s\n", v[i].c_str());
		}
	}
	return 0;
}