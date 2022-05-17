#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}
vector<int> v;
int N, K;
int main()
{
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), comp);

	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		sum += v[i];
	}
	cout << sum - (K-1)*(K)/2;
	return 0;
}