#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, jew, _max, res;
vector <int> v;

void bSearch(int left, int right)
{
	if (left > right)
	{
		cout << res;
		return;
	}
	int mid = (left + right) / 2;
	int jcnt, pcnt = 0;

	for (int i = 0; i < M; i++)
	{
		jcnt = v[i];
		while (mid < jcnt)
		{
			jcnt -= mid;
			pcnt++;
		}
		pcnt++;
	}
	if (pcnt > N)
		bSearch(mid + 1, right);
	else
	{
		res = mid;
		bSearch(left, mid - 1);
	}
		
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> jew;
		v.push_back(jew);
		_max = max(_max, jew);
	}
	bSearch(1, _max);
	return 0;
}