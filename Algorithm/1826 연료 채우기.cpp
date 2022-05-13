#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;
int N, location, gas, town, rest ,dist, cnt = 0;
vector<pii> station;
priority_queue <int> pq;
bool flag = true;
const int INF = 100000000;

int main()
{
	FIO;
	cin >> N;
	station.push_back({ 0, 0 });
	for (int i = 0; i < N; i++)
	{
		cin >> location >> gas;
		station.push_back({ location, gas });
	}
	cin >> town >> rest;
	station.push_back({ town, 0 });
	station.push_back({ INF, 0 });
	sort(station.begin(), station.end());
	int cur_loc = 0, cur = 0, next = 1, next_loc;

	while (cur_loc != town && flag)
	{
		next_loc = station[next].first;
		dist = next_loc - cur_loc;
		if (next_loc != INF && rest >= dist)
		{
			cur_loc = next_loc;
			next_loc = station[next + 1].first;
			rest -= dist;
			cur++;
			next++;
			pq.push(station[cur].second);
		}
		else
		{
			while (rest < dist)
			{
				if (pq.empty())
				{
					flag = false;
					break;
				}
				rest += pq.top();
				pq.pop();
				cnt++;
			}
		}
	}
	if (flag)
		cout << cnt;
	else
		cout << -1;
	return 0;
}