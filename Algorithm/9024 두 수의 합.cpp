#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<int> arr;
int T, n, K;

int main()
{
	FIO;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n >> K;
		arr.resize(0); arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int start = 0, end = n - 1, diff = 1e9, tmp, cnt = 0;
		sort(arr.begin(), arr.end());
		while (start < end)
		{
			int sum = arr[start] + arr[end];

			tmp = abs(sum - K);
			if (diff >= tmp)
			{
				if (diff > tmp)
				{
					cnt = 0;
					diff = tmp;
				}
				cnt++;
			}

			if (sum > K)
			{
				end--;
			}
			else if (sum <= K)
				start++;
		}
		cout << cnt << "\n";
	}	
	return 0;
}