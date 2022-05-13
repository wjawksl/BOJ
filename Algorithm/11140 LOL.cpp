#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc;
	char s[60];
	string str, tmp;
	bool flag, flag1, flag2, flag3;

	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		flag = false;
		flag1 = false;
		flag2 = false;
		flag3 = false;

		scanf("%s", s);
		getchar();

		str = s;
		if (str.length() >= 3)
		{
			for (int j = 0; j < str.length() - 2; j++)
			{
				if (!str.substr(j, 3).compare("lol"))
				{
					flag = true;
					printf("%d\n", 0);
					break;
				}
			}
		}
		
		if (flag)
			continue;

		if (str.length() >= 2)
		{
			for (int j = 0; j < str.length() - 2; j++)
			{
				tmp = str.substr(j, 3);
				if (tmp[0] == 'l' && tmp[2] == 'l')
				{
					flag1 = true;
					printf("%d\n", 1);
					break;
				}
			}
			if (!flag1)
			{
				for (int j = 0; j < str.length() - 1; j++)
				{
					if (!(str.substr(j, 2).compare("ll") && str.substr(j, 2).compare("lo") && str.substr(j, 2).compare("ol")))
					{
						flag2 = true;
						printf("%d\n", 1);
						break;
					}
				}
			}
			
		}
		

		if (flag1 || flag2)
			continue;

		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'l' || str[j] == 'o')
			{
				printf("%d\n", 2);
				flag3 = true;
				break;
			}
		}

		if (flag3)
			continue;

		printf("%d\n", 3);
	}
	return 0;
}