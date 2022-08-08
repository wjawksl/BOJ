#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int C;
int ans, cnt;

int main()
{
	string str;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> str;
		cnt = 0;
		for (int j = 0; j < str.size(); j++)
		{			
			if (str.size() - j >= 3)
			{
				string f = str.substr(j, 3);
				if (f == "for")
				{
					cnt++;					
					continue;
				}
			}
			if (str.size() - j >= 5)
			{
				string w = str.substr(j, 5);
				if (w == "while")
				{
					cnt++;
					continue;
				}			
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}