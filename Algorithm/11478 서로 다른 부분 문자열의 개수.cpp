#include<iostream>
#include<algorithm>
#include<set>
#include<string>

using namespace std;

set<string> s;
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 1; j < str.size() - i + 1; j++)
		{
			s.insert(str.substr(i, j));
		}
	}
	cout << s.size();
	return 0;
}