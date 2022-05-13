#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int arr[100000];

int main()
{
	int n;
	ll k, sum, cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum > k)
			{
				cnt += n - j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}