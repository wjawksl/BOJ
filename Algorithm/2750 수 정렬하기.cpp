#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	vector <int> v;
	int N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n);
		v.push_back(n);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", v[i]);
	}
	return 0;
}
