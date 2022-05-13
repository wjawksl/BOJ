#include<iostream>
#include<queue>
#include<algorithm>
#define FIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, command;
priority_queue <int> pq;
int main()
{
	FIO;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n"; pq.pop();
			}		
		}
		else
			pq.push(command);
	}
	return 0;
}