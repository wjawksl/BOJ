#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int a, b, N, cnt = 0;
	vector<pair<int, int>> condo;
	bool flag;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		condo.push_back(make_pair(a, b));
	}
	for (int i = 0; i < N; i++)
	{
		flag = true;
		for (int j = 0; j < N; j++)
		{
			if (j == i) continue;
			if (condo[i].first > condo[j].first)
			{
				if (condo[i].second >= condo[j].second)
				{
					flag = false;
					break;
				}
			}
			if (condo[i].second > condo[j].second)
			{
				if (condo[i].first >= condo[j].first)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag) cnt++;
	}
	printf("%d", cnt);
	return 0;
}