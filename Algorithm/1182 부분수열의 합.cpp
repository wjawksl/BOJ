#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, S, num, sum, cnt = 0;
	vector <int> p;
	vector <int> v;
	vector <int> tmp;

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
		p.push_back(0);
	}
	for (int i = 0; i < N; i++)
	{
		p[i] = 1;
		tmp = p;
		do
		{
			sum = 0;
			for (int j = 0; j < N; j++)
			{
				if (p[j]) sum += v[j];
			}
			if (sum == S) cnt++;
		} while (prev_permutation(p.begin(), p.end()));
		p = tmp;
	}
	printf("%d", cnt);
	return 0;
}
