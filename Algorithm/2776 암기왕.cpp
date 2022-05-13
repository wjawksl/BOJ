#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num;
vector <int> v;

bool bSearch(int left, int right)
{
	if (left > right)
		return false;

	int mid = (left + right) / 2;

	if (v[mid] == num)
		return true;
	else if (num < v[mid])
		return bSearch(left, mid - 1);
	else
		return bSearch(mid + 1, right);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, tc, n;

	cin >> tc;
	for (int a = 0; a < tc; a++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> num;
			if(bSearch(0, v.size() - 1))cout << "1\n";
			else cout << "0\n";
		}
		v.clear();
	}
	return 0;
}