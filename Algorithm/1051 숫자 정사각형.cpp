#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	vector <vector <int>> rect;
	vector <int> n;
	int N, M, sml, big, p,q, l;
	bool flag = false;
	char s[60];

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < M; j++)
		{
			n.push_back((s[j] - '0'));
		}
		rect.push_back(n);
		n.clear();
	}
	
	big = max(N, M);
	sml = min(N, M);
	l = sml - 1;

	while (true)
	{
		p = 0;
		for (int i = l; i < N; i++)
		{
			q = 0;
			for (int j = l; j < M; j++)
			{
				if (rect[p][q] == rect[p][q + l] && rect[p][q] == rect[p + l][q] && rect[p][q] == rect[p + l][q + l])
				{
					printf("%d", int(pow(l+1, 2)));
					flag = true;
					break;
				}
				q++;
			}
			p++;
			if (flag) break;
		}
		if (flag) break;
		l--;
	}
	return 0;
}
