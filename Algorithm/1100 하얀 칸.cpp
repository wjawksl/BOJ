#include<iostream>
#include<string.h>

int main()
{
	char chess[10];
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%s", chess);
		getchar();
		for (int j = 0; j < 8; j++)
		{
			if (i % 2)
			{
				if (j % 2)
				{
					if (chess[j] == 'F')
					{
						cnt++;
					}
				}
				
			}
			else
			{
				if (!(j % 2))
				{
					if (chess[j] == 'F')
					{
						cnt++;
					}
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}