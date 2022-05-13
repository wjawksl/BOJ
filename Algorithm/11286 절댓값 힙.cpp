#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#define FIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b; // true라면 a,b를 swap
		else return abs(a) > abs(b);// true라면 a,b를 swap
	}
};
int N, command;
priority_queue <int, vector<int>, compare> pq;
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