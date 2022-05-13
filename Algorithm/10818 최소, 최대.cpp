#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	vector <int> v;
	int N,n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n);
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	printf("%d %d", v[0], v[N - 1]);
	return 0;
}
