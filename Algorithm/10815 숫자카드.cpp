#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> v;
int num;

bool bSearch(int left, int right)
{
	int mid = (left + right) / 2;

	if (v[mid] == num)
		return true;
	else if (left > right)
		return false;
	else
	{
		if (num < v[mid])
			return bSearch(left, mid - 1);
		else
			return bSearch(mid + 1, right);
	}
}
int main()
{
	int N, M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (bSearch(0, N - 1))
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}