#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int n1, n2,tmp;
	scanf("%d %d", &n1, &n2);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	for (int i = 0; i < n2; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d ", v[i]);
	}

	return 0;
}