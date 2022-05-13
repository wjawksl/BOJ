#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int accSum[100005], area[100005];
int N, ans = 0;
int main()
{
	FIO;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> area[i];
		accSum[i] = area[i] + accSum[i - 1];
	}
	int fixedSum = accSum[N] - accSum[1], sum1, sum2;
	for (int i = 2; i < N + 1; i++)
	{
		sum1 = fixedSum - area[i];
		sum2 = accSum[N] - accSum[i];

		ans = max(ans, sum1 + sum2);
	}
	for (int i = N - 1; i > 1; i--)
	{
		sum1 = accSum[i] - accSum[1];
		sum2 = accSum[N - 1] - accSum[i - 1];

		ans = max(ans, sum1 + sum2);
	}
	fixedSum = accSum[N - 1];
	for (int i = N - 1; i > 0; i--)
	{
		sum1 = fixedSum - area[i];
		sum2 = accSum[i - 1];

		ans = max(ans, sum1 + sum2);
	}
	cout << ans;
	return 0;
}