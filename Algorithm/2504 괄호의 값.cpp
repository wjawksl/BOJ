#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	vector <char> v;
	int res=0;
	int tmp = 1;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (!v.empty())
		{
			if (v.back() == '(')
			{
				if (str[i] == ')')
				{
					if(str[i-1] == '(')
						res += tmp;
					tmp /= 2;
					v.pop_back();
				}
				else
				{
					if (str[i] == '(')
					{
						tmp *= 2;
					}
					else if (str[i] == '[')
					{
						tmp *= 3;
					}
					v.push_back(str[i]);
				}
			}
			else if (v.back() == '[')
			{
				if (str[i] == ']')
				{
					if (str[i - 1] == '[')
						res += tmp;
					tmp /= 3;
					v.pop_back();
				}
				else
				{
					if (str[i] == '(')
					{
						tmp *= 2;
					}
					else if (str[i] == '[')
					{
						tmp *= 3;
					}
					v.push_back(str[i]);
				}
			}
		}
		else
		{
			if (str[i] == '(')
			{
				tmp *= 2;
			}
			else if (str[i] == '[')
			{
				tmp *= 3;
			}
			v.push_back(str[i]);
		}
	}
	if (v.empty())
		printf("%d", res);
	else
		printf("0");

	return 0;
}