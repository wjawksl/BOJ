#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, K;
vector<int> sensor;
vector<int> dist;
int main()
{
	int ans = 0;
	cin >> N >> K;

	sensor.resize(N); dist.resize(N - 1);

	for (int i = 0; i < N; i++)
	{
		cin >> sensor[i];
	}
	sort(sensor.begin(), sensor.end());
	for (int i = 1; i < N; i++)
	{
		dist[i -1] = sensor[i] - sensor[i - 1];
	}
	sort(dist.begin(), dist.end());

	for (int i = 0; i < N - K; i++)
	{
		ans += dist[i];
	}
	cout << ans;
	return 0;
}