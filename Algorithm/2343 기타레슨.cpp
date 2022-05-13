#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;

vector <int> v;
int N,M;
ll sum = 0, res;
bool flag;
void bSearch(ll left, ll right)
{
	if (left > right)
	{
		cout << res;
		return;
	}

	ll tmp = 0, mid = (left + right) / 2;

	int cnt = 1;
	flag = true;

	for (int i = 0; i < N; i++)
	{
		if (v[i] > mid)
		{
			flag = false;
			break;
		}

		tmp += v[i];
		if (tmp > mid)
		{
			tmp = v[i];
			cnt++;
		}

	}

	if (cnt > M || !flag)
		bSearch(mid + 1, right);

	else if (cnt <= M)
	{
		res = mid;
		bSearch(left, mid - 1);
	}
}

int main()
{	
	int num;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	bSearch(1, sum);
	
	return 0;
}
