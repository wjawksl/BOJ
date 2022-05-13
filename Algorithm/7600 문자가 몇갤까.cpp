#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	char tmp[260];
	int cnt,n,idx;
	bool visited[30];
	
	scanf("%[^\n]s",tmp);
	while(strcmp(tmp,"#"))
	{
		memset(visited, false, sizeof(bool) * 30);
		cnt = 0;
		for (int i = 0; i < strlen(tmp); i++)
		{
			n = (int)tmp[i];
			if (65 <= n && n <= 90) 
			{
				idx = n - 65;
				if (!visited[idx])
				{
					visited[idx] = true;
					cnt++;
				}	
			}
			else if (97 <= n && n <= 122)
			{
				idx = n - 97;
				if (!visited[idx])
				{
					visited[idx] = true;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		getchar();
		scanf("%[^\n]s", tmp);
	}


	return 0;
}