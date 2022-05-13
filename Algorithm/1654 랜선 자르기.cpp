#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
vector <ll> v;
ll N, cnt;
void get_ans(ll left, ll right)
{
	ll mid = (left + right) / 2;

	if (left > right)
	{
		cout << mid;
		return;
	}
	
	for (int i = 0; i < v.size(); i++)
		cnt += v[i] / mid;

	if (cnt < N)
	{
		right = mid - 1;
		cnt = 0;
		get_ans(left, right);
	}
	else
	{
		left = mid + 1;
		cnt = 0;
		get_ans(left, right);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll K, n, left = 0, right,mid, cnt = 0;
	ll sum = 0,tmp;

	cin >> K >> N;	

	for (int i = 0; i < K; i++)
	{
		cin >> n;
		v.push_back(n);
		sum += n;
	}
	right = sum / N;
	
	get_ans(1, right);

	return 0;
}