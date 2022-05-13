#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector <pair<int,int>> v;
	int N, n1, n2;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &n1, &n2);
		v.push_back(make_pair(n1, n2));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}
	
	return 0;
}