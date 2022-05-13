#include<iostream>
#include<string.h>

int main()
{
	char plain[30010],key[30010],cipher;
	int tmp;
	scanf("%[^\n]s", plain);
	getchar();
	scanf("%[^\n]s", key);
	int n= (int)plain[0];
	char k;
	for (int i = 0; i < strlen(plain); i++)
	{
		if (plain[i] == ' ')
		{
			printf("%c", plain[i]);
			continue;
		}
		tmp = ((int)plain[i] - (int)key[i % strlen(key)]) + 122;

		if (tmp > 122) cipher = tmp % 122 + 96;
		else cipher = tmp; 
		printf("%c", cipher);
	}
	
	return 0;
}