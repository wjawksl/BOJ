#include<iostream>
#include<vector>
#include<algorithm>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int arr[1000005];
int idx[1000005];
vector<int> v;
vector<int> rev;
int main()
{
	FIO;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	idx[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (v.back() < arr[i])
		{
			v.push_back(arr[i]);
			idx[i] = v.size();
		}
		else
		{
			int L = 0, R = v.size() - 1, mid;
			while (L < R)
			{
				mid = (L + R) / 2;
				if (v[mid] >= arr[i])
				{
					R = mid;
				}
				else
				{
					L = mid + 1;
				}
			}
			v[L] = arr[i];
			idx[i] = L + 1;
		}
	}

	int ans = v.size(), A = v.size();
	cout << ans << "\n";
		
	for (int i = N - 1; i >= 0; i--)
	{
		if (ans == idx[i])
		{
			rev.push_back(arr[i]);
			ans--;
		}
	}
	while (rev.size() != 0)
	{
		cout << rev.back() << " ";
		rev.pop_back();
	}
	return 0;
}