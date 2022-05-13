#include<iostream>
#include<string>

using namespace std;

int main()
{
	int tmp_j;
	bool flag_t, flag_f;
	char s[100010], t[100010];
	string S, T, tmp;

	while (scanf("%s %s", s, t) == 2)
	{
		//if (s[0] == '\n' && t[0] == '\n') break;
		getchar();
		tmp_j = 0;
		tmp = "";
		S = s;
		T = t;
		
		flag_t = true;
		flag_f = false;
		if (S.length() > T.length())
			printf("No\n");
		else
		{
			for (int i = 0; i < S.length(); i++)
			{
				for (int j = tmp_j; j < T.length(); j++)
				{
					if (S[i] == T[j])
					{
						tmp = tmp + S[i];
						if (!tmp.compare(S))
						{
							flag_f = true;
							break;
						}
						tmp_j = j + 1;
						break;
					}
					if (j == T.length() - 1) flag_t = false;
				}
				if (!flag_t)
				{
					printf("No\n");
					break;
				}
				if (flag_f)
				{
					printf("Yes\n");
					break;
				}
			}
		}
	}
	return 0;
}