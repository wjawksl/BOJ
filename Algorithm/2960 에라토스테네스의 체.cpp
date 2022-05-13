#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	vector <int> v;
	int N, K, num, i, cnt = 0;
	bool flag;

	scanf("%d %d", &N, &K);
	for (int i = 2; i < N+1; i++)
	{
		v.push_back(i);
	}
	while (true)
	{
		flag = false;
		for (i = 0; i <= N; i++)
		{
			if (v[i] != 0)
			{
				num = v[i];
				break;
			}
		}
		for (int j = i; j < v.size(); j+= num)
		{
			if (v[j] != 0)
			{
				cnt++;
				if (cnt == K)
				{
					printf("%d", v[j]);
					flag = true;
					break;
				}
				v[j] = 0;
			}
			
		}
		if (flag) break;
	}
	return 0;
}