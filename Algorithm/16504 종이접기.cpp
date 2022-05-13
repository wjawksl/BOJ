#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main()
{
	vector <vector<int>> v;
	vector<int> tmp;
	int N, n;
	ll sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &n);
			tmp.push_back(n);
		}
		v.push_back(tmp);
		tmp.clear();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += v[i][j];
		}
	}
	printf("%lld", sum);
	return 0;
}