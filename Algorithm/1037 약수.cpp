#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector <int> v;
	int cnt,n;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &n);
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	printf("%d", v[0] * v[v.size() - 1]);
	return 0;
}