#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> v;

int Bsearch_upper(int left, int right, int res)
{
	if (left > right)
		return right;

	int mid = (left + right) / 2;

	if(v[mid] <= res)
		return Bsearch_upper(mid + 1, right, res);
	else
		return Bsearch_upper(left, mid-1, res);
}
int Bsearch_lower(int left, int right, int res)
{
	if (left > right)
		return left;
	
	int mid = (left + right) / 2;

	if (v[mid] >= res)
		return Bsearch_lower(left, mid-1, res);
	else
		return Bsearch_lower(mid + 1, right, res);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M, num;

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
		cout << Bsearch_upper(0, N-1, num) - Bsearch_lower(0, N-1, num) + 1 << " ";
	}
	
	return 0;
}