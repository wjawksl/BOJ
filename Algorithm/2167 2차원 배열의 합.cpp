#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main()
{
	vector <vector<int>> v;
	vector<int> tmp;
	int N, M, K, n, a,b,x,y;
	ll sum;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &n);
			tmp.push_back(n);
		}
		v.push_back(tmp);
		tmp.clear();
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		sum = 0;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		for (int j = a-1; j <= x-1; j++)
		{
			for (int k = b-1; k <= y-1; k++)
			{
				sum += v[j][k];
			}
		}
		printf("%lld\n", sum);
	}
	
	return 0;
}