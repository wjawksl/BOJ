#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int visited[4000005];
vector <int> prime;
int main()
{
	long long int N;
	int cnt = 0;
	cin >> N;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (visited[i]) continue;		
		for (int j = i + i; j <= N; j += i)
		{
			if (visited[i]) continue;
			visited[j] = true;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if(!visited[i]) prime.push_back(i);		
	}
	long long int sum = 0;
	int idx = 0;
	for (int i = 0; i < prime.size(); i++)
	{
		sum += prime[i];
		while (sum > N)
		{
			sum -= prime[idx++];
		}
		if (sum == N) cnt++;		
	}
	cout << cnt;
	return 0;
}