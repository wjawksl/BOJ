#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

int main()
{
	vector <string> v;
	string str;
	 
	int N, M;
	scanf("%d %d", &N, &M);
	char* s = (char*)malloc(sizeof(char) * M + 5);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		getchar();
		str = s;
		v.push_back(str);
	}

	for (int i = M - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			switch (v[j][i])
			{
			case 45:
				printf("%c", 124);
				break;
			case 124:
				printf("%c", 45);
				break;
			case 47:
				printf("%c", 92);
				break;
			case 92:
				printf("%c", 47);
				break;
			case 94:
				printf("%c", 60);
				break;
			case 60:
				printf("%c", 118);
				break;
			case 118:
				printf("%c", 62);
				break;
			case 62:
				printf("%c", 94);
				break;
			default:
				printf("%c", v[j][i]);
				break;
			}
		}
		printf("\n");
	}

	return 0;
}