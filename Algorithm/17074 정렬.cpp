#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
int check_arr(vector<ll> v1, vector<ll> v2,int size)
{
	int c = 0;
	vector <ll> t1;
	vector <ll> t2;
	for (int i = 0; i < size; i++)
	{
		t1 = v1;
		t2 = v2;
		t1.erase(t1.begin() + i);
		t2.erase(t2.begin() + i);
		sort(t1.begin(), t1.end());
		if (t1 == t2) c++;
	}
	return c;
}
int main()
{
	vector <ll> v;
	vector <ll> tmp;
	vector <ll> tmp1;
	vector <ll> tmp2;
	int N, cnt = 0;
	ll num;
	bool flag = false;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &num);
		v.push_back(num);
	}
	tmp = v;
	sort(tmp.begin(), tmp.end());
	if (tmp == v)
	{
		cnt = v.size();
	}
	else if (N < 5)
	{
		tmp1 = v;
		tmp2 = v;
		cnt = check_arr(tmp1, tmp2, N);
	}
	else
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				if (i == 0)
				{
					for (int j = 0; j < 5; j++)
					{
						tmp1.push_back(v[j]);
						tmp2.push_back(v[j]);
					}
					cnt = check_arr(tmp1, tmp2, 5);
				}
				else if (i == 1)
				{
					if (!tmp1.empty())
					{
						cnt = 0;
						break;
					}
					for (int j = 0; j < 5; j++)
					{
						tmp1.push_back(v[j]);
						tmp2.push_back(v[j]);
					}
					cnt = check_arr(tmp1, tmp2, 5);
				}
				else if (i == N - 2)
				{
					if (!tmp1.empty())
					{
						cnt = 0;
						break;
					}
					for (int j = i - 3; j < i + 2; j++)
					{
						tmp1.push_back(v[j]);
						tmp2.push_back(v[j]);
					}
					cnt = check_arr(tmp1, tmp2, 5);
				}
				else
				{
					if (!tmp1.empty())
					{
						cnt = 0;
						break;
					}
					for (int j = i - 2; j <= i + 2; j++)
					{
						tmp1.push_back(v[j]);
						tmp2.push_back(v[j]);
					}
					cnt = check_arr(tmp1, tmp2, 5);
				}
				
			}
		}
	}
	printf("%d", cnt);
	return 0;
}