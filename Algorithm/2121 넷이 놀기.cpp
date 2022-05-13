#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<iterator>


using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

map <pair <ll, ll>, ll> pos;

ll N, x, y;
ll A, B, cnt = 0;

int main()
{
	FIO;

	cin >> N;
	cin >> A >> B;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		pos.insert({ { x,y }, 0 });
	}
	for (auto it = pos.begin(); it != pos.end(); it++)
	{
		ll cur_x = it->first.first, cur_y = it->first.second;
		if (pos.count({ cur_x + A , cur_y }) && pos.count({ cur_x, cur_y + B }) && pos.count({ cur_x + A , cur_y + B })) cnt++;
	}
	cout << cnt;
	return 0;
}