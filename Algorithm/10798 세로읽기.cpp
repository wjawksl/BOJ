#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<exception>

using namespace std;

int main()
{
	char s[20];
	vector <string> v;
	string str;
	int _max = 0, cur_len;
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", s);
		str = s;
		cur_len = str.length();
		str += "               ";
		_max = max(cur_len, _max);
		v.push_back(str);
	}

	//fill(v.begin(), v.end(), " ");
	for (int i = 0; i < _max; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (v[j][i] != ' ') printf("%c", v[j][i]);
		}
	}
	return 0;
}