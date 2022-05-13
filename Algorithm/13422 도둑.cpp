#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector <int> house;
vector<int> accSum;
int T, N, M, K;
int main()
{
	FIO;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> K;
		house.resize(0); house.resize(N); int idx = 0, money, cnt = 0;
		accSum.resize(0); accSum.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> house[i];
			if (i == 0)
			{
				accSum[0] = house[i];
				continue;
			}
			accSum[i] = house[i] + accSum[i - 1];
		}
		for (int i = 0; i < N; i++)
		{
			money = 0;
			int start = i, end = (i + M - 1) % N;
			if (start <= end)
			{
				money = accSum[end] - accSum[start] + house[start];
			}
			else if (end < start)
			{
				money = accSum[N - 1] - (accSum[start - 1] - accSum[end]);
			}			
			if (money < K) cnt++;
			if (N == M) break;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}