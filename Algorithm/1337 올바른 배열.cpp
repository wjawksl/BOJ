#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector <int> v;
	int N, num, tmp = 4, cnt = 4;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	if (N != 1)
	{
		for (int i = 0; i < N - 1; i++)
		{
			tmp = 4;
			for (int j = i + 1; j < N; j++)
			{
				if (v[j] - v[i] >= 5)
				{
					cnt = min(cnt, tmp);
					break;
				}
				tmp--;
				if (tmp == 0 || j == N-1)
				{
					cnt = min(cnt, tmp);
					break;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}