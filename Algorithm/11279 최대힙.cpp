#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue <int> pq;
	int N, num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(num);
	}
	return 0;
}