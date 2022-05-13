#include<iostream>
#include<algorithm>

using namespace std;

int arr[5000005];
int main()
{
	int N, L, len, idx = 0;
	int fMin, sMin = 1e9 + 1, tMin = 1e9 + 1;
	cin >> N >> L;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
	}
	fMin = arr[1];
	len = 1;
	for (int i = 2; i < N; i++)
	{
		if (i <= L)
		{			
			if (fMin > arr[i])
			{
				sMin = fMin;
				fMin = arr[i];				
			}
			else if(sMin > arr[i])
			{
				tMin = sMin;
				sMin = arr[i];
			}
			else
			{
				tMin = min(tMin, arr[i]);
			}
		}
		else
		{
			if (fMin == arr[idx])
			{
				fMin = sMin;
				sMin = fMin;
				//len--;
			}
			if (fMin > arr[i])
			{
				
				fMin = arr[i];
			}
			else
			{
				sMin = min(sMin, arr[i]);
			}			
		}
	}
	return 0;
}