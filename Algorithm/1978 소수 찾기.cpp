#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	vector <int> n;
	int N, num, cnt=0;
	

	scanf("%d", &N);
	for (int i = 0; i < 1001; i++)
	{
		n.push_back(i);
	}
	for (int i = 2; i <= sqrt(1000); i++)
	{
		if (n[i] != 0)
		{
			for (int j = i*2; j < 1001; j+=i)
			{
				n[j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (n[num] == num && num != 1) cnt++;
	}
	printf("%d", cnt);
	return 0;
}