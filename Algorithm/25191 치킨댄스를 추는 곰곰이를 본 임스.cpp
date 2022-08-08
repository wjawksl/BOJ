#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, coke, beer;
int main()
{
	cin >> N;
	cin >> coke >> beer;

	int cnt = coke / 2 + beer;

	if (cnt > N) cnt = N;
	cout << cnt;

	return 0;
}