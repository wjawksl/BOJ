#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	char d[2510],w[2510];
	string docu, word;
	scanf("%[^\n]s", d);
	getchar();
	scanf("%[^\n]s", w);
	docu = d;
	word = w;
	int cnt = 0, len = docu.length() - word.length() + 1;
	for (int i = 0; i < len; i++)
	{
		if (docu[i] == word[0])
		{
			if (!word.compare(docu.substr(i, word.length())))
			{
				i += word.length()-1;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}