#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector <int> arr(25);
int N;
void HanoiTop(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
	}
	else
	{
		HanoiTop(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		HanoiTop(n - 1, by, from, to);
	}
}

int main()
{
	FIO;
	cin >> N;
	arr[0] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		arr[i] = pow(2,i) - 1;
	}
	cout << arr[N] << "\n";
	HanoiTop(N, 1, 2, 3);
	
	return 0;
}