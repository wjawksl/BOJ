#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
vector<int> cnt(1005);
bool comp(int n1, int n2)
{
	return n1 > n2;
}
int main()
{
	int N, M, brand;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> brand;
		cnt[brand]++;
	}
	cnt.erase(cnt.begin() + M + 1, cnt.end());
	sort(cnt.begin(), cnt.end(), comp);
	cout << cnt[0];
	return 0;
}