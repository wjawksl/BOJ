#include<iostream>
#include<string>

using namespace std;
int main()
{
	int tc;
	char s[40],end;
	string str,tmp;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		scanf("%s", s);
		getchar();
		str = s;
		tmp = str.substr(str.length()-2,2);

		if (!str.substr(str.length() - 2, 2).compare("ne"))
			str = str.replace(str.length() - 2, 2, "anes");
		else
		{
			end = str[str.length() - 1];
			if (end == 'a')
				str += "s";
			else if (end == 'i' || end == 'y')
				str = str.replace(str.length() - 1, 1, "ios");
			else if (end == 'l')
				str += "es";
			else if (end == 'n')
				str = str.replace(str.length() - 1, 1, "anes");
			else if (end == 'o')
				str += "s";
			else if (end == 'r')
				str += "es";
			else if (end == 't')
				str += "as";
			else if (end == 'u')
				str += "s";
			else if (end == 'v')
				str += "es";
			else if (end == 'w')
				str += "as";
			else
				str += "us";

		}
		printf("%s\n", str.c_str());
		
	}
	return 0;
}