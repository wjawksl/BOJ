#include<iostream>
#include<algorithm>
#include<queue>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;
int N, card, n1, n2;
long long int res = 0;
int main()
{
	FIO;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		pq.push(card);
	}
	while (pq.size() != 1)
	{
		n1 = pq.top();
		pq.pop();
		n2 = pq.top();
		pq.pop();
		res += n1 + n2;
		pq.push(n1 + n2);
	}
	
	cout << res;

	return 0;
}