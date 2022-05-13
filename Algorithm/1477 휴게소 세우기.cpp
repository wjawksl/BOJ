#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, L, num, res;
vector <int> v;

void bSearch(int left, int right)
{

	if (left > right)
	{
		cout << res;
		return;
	}
	int mid = (left + right) / 2;
	int _max = 0;
	vector <int> tmp(v);

	for (int i = 0; i < N - 1; i++)
	{
		if (tmp[i] + mid < tmp[i + 1])
		{
			tmp.emplace(tmp.begin() + i, mid);
		}
	}

	for (int i = 0; i < N - 1; i++)
		_max = max(_max, v[i + 1] - v[i]);

	if ((N + M) >= tmp.size() && _max == mid)//!! && ¿¬»ê Àß¸øµÊ
	{
		bSearch(left, mid - 1);
		res = mid;
	}
	else
	{
		bSearch(mid + 1, right);
	}
}
int main()
{
	
	cin >> N >> M >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	v.emplace(v.begin(), 0);
	v.push_back(L);

	bSearch(1,L);

	return 0;
}