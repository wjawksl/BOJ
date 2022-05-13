#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

bool comp(string c1, string c2)
{
	transform(c1.cbegin(), c1.cend(), c1.begin(), ::tolower);
	transform(c2.cbegin(), c2.cend(), c2.begin(), ::tolower);
	return c1 < c2;
}
int main()
{
	
	vector <string> tmp;
	vector <string> v;
	int tc;
	char s[30];
	string str;

	scanf("%d", &tc);
	while (tc)
	{
		for (int i = 0; i < tc; i++)
		{
			scanf("%s", s);
			str = s;
			v.push_back(str);
		}
		sort(v.begin(), v.end(), comp);
		printf("%s\n", v[0].c_str());
		scanf("%d", &tc);
		
		v.clear();
	}
	
	return 0;
}