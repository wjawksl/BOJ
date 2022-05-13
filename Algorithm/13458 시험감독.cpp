#include<iostream>
#include<algorithm>

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
typedef long long int ll;

int testSite[1000005];
int N, B, C;
ll cnt = 0;

int main()
{
	FIO;

	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> testSite[i];
	}
	cin >> B >> C;
	for (int i = 1; i < N + 1; i++)
	{
		int temp = testSite[i] - B;
		if (temp <= 0)
			cnt++;
		else
		{
			cnt++;
			if (temp - C <= 0)
				cnt++;
			else
			{
				if (temp % C == 0)
					cnt += temp / C;
				else
					cnt += temp / C + 1;
			}
				
		}
	}
	cout << cnt;
	return 0;
}