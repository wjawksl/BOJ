#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define INF -1e9;
using namespace std;

vector <int> arr;
vector <int> sorted;
vector <int> Idx;
vector <int> sortedIdx;
int N;
void merge(int left, int mid, int right)
{
	int l = left;
	int r = mid + 1;
	int idx = left;

	while (l <= mid && r <= right)
	{
		if (arr[l] <= arr[r])
		{
			sorted[idx] = arr[l];
			sortedIdx[idx] = Idx[l];
			idx++; l++;
		}
		else
		{
			sorted[idx] = arr[r];
			sortedIdx[idx] = Idx[r];
			idx++; r++;
		}		
	}
	if (l > mid)
	{
		for (int i = r; i <= right; i++)
		{
			sorted[idx] = arr[i];
			sortedIdx[idx] = Idx[i];
			idx++;
		}
	}
	else
	{
		for (int i = l; i <= mid; i++)
		{
			sorted[idx] = arr[i];
			sortedIdx[idx] = Idx[i];
			idx++;
		}
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
		Idx[i] = sortedIdx[i];
	}
}
void mergeSort(int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main()
{
	FIO;
	int num, answer = INF;
	cin >> N;
	sorted.resize(N);
	sortedIdx.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
		Idx.push_back(i);
	}
	
	mergeSort(0, N - 1);	
	for (int i = 0; i < N; i++)
	{
		answer = max(Idx[i] - i, answer);
	}
	cout << answer + 1;
	return 0;
}