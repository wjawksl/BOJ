#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector <int> arr;
int N;
void QuickSort(int left, int right)
{
	if (left >= right) return;
	int pivot = left;
	int lo = left + 1, hi = right;

	while (lo <= hi)
	{
		while (lo <= right && arr[lo] <= arr[pivot]) lo++;
		while (hi > left && arr[hi] >= arr[pivot]) hi--;

		if (lo > hi) swap(arr[pivot], arr[hi]);
		else swap(arr[lo], arr[hi]);
	}
	QuickSort(left, hi - 1);
	QuickSort(hi + 1, right);
}
int main()
{
	FIO;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	mt19937 seed;
	shuffle(arr.begin(), arr.end(), seed);
	QuickSort(0, N - 1);
	for (int i = 0; i < N; i++)
	{		
		cout << arr[i] << "\n";
	}
	return 0;
}