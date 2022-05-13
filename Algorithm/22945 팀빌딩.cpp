#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int arr[100005];
int N, ans = 0;

int main()
{
	cin >> N;
	int start = 1, end = N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
	}
	while (start != end)
	{
		ans = max(ans, min(arr[start], arr[end]) * (end - start - 1));
		if (arr[start] > arr[end])
		{
			end--;
		}
		else start++;
	}
	cout << ans;
	return 0;
}