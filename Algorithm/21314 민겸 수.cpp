#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
string str;
string num = "";
int main()
{
	int M_cnt = 0,tmp;
	cin >> str;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'K')
		{
			//num += to_string(5 * (int)pow(10, M_cnt));
			num += "5";
			for (int i = 0; i < M_cnt; i++)
				num += "0";
			M_cnt = 0;
		}
		else if (str[i] == 'M')
		{
			M_cnt++;
		}
	}
	if (M_cnt != 0)
	{
		for (int i = 0; i < M_cnt; i++)
			num += "1";
	}
	cout << num << "\n";
	num = "";
	M_cnt = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'K')
		{
			for (int i = 0; i < M_cnt; i++)
			{
				if (i == 0)
					num += "1";
				else
					num += "0";
			}
			num += "5";
			M_cnt = 0;
		}
		else if (str[i] == 'M')
		{
			M_cnt++;
		}
	}
	if (M_cnt != 0)
	{
		for (int i = 0; i < M_cnt; i++)
		{
			if (i == 0)
				num += "1";
			else
				num += "0";
		}
	}
	cout << num;
	return 0;
}