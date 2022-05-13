#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int GCD(int n1, int n2)
{
	int tmp;
	while (n2 != 0)
	{
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	return n1;
}

int main()
{
	int tc, N, num;
	long long sum;
	vector <int> v;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		sum = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &num);
			v.push_back(num);
		}
		for (int a = 0; a < N - 1; a++)
		{
			for (int b = a + 1; b < N; b++)
			{
				sum += GCD(max(v[a], v[b]), min(v[a], v[b]));
			}
		}
		printf("%lld\n", sum);
		v.clear();
	}

	return 0;
}
