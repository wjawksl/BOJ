#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool comp(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
int main()
{
	vector<pair <int, int>> vp;
	int N, a, b, num1, num2, cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		vp.push_back(make_pair(a, b));
	}
	sort(vp.begin(), vp.end(),comp);
	num1 = vp[0].second;
	sort(vp.begin(), vp.end());
	num2 = vp[N-1].first;
	
	if (num1 > num2) printf("%d", 0);
	else printf("%d", num2 - num1);
	
	return 0;
}