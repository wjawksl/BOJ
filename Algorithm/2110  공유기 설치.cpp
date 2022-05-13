#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> v;
int N, C,res;

void bSearch(int left, int right)
{
	int mid = (left + right) / 2, idx = 0, cnt = 1;

	if (left > right)
	{
		printf("%d", mid);
		return;
	}
	for (int i = 1; i < N; i++)
	{
		if (v[i] - v[idx] >= mid)
		{
			cnt++;
			idx = i;
		}
		else
			continue;
	}
	if (cnt >= C)
	{
		bSearch(mid + 1, right);
	}
	else
		bSearch(left, mid - 1);
}
int main()
{
	int x;
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	bSearch(1, v[N-1] - 1);
	return 0;
}