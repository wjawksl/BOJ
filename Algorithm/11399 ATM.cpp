#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector <int> v;

int main()
{
	int N, Pi,res = 0, tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Pi;
		v.push_back(Pi);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		tmp += v[i];
		res += tmp;
	}
	cout << res;
	return 0;
}