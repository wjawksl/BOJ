#include<iostream>
#include<algorithm>

using namespace std;

int arr[30][30];
int comb(int n, int r)
{
	if (r == 0 || n == r)
	{
		arr[n][r] = 1;
		return 1;
	}
		
	if (arr[n][r] == 0)
	{
		arr[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
	}
	return arr[n - 1][r - 1] + arr[n - 1][r];
}
int main()
{
	int T, N, M;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		cout << comb(M, N) << "\n";
	}
	return 0;
}