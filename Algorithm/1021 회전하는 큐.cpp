#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque <int> dq;
	int N,M;
	int pos, cnt = 0;
	cin >> N >> M;
	
	for (int i = 1; i < N + 1; i++)
		dq.push_back(i);

	for (int i = 0; i < M; i++) 
	{
		cin >> pos;
		for (int j = 0; j < N; j++)
		{
			if (dq[j] == pos)
			{
				if (j > (dq.size() - 1) / 2)
				{
					while (dq.front() != pos)
					{
						dq.push_front(dq.back());
						dq.pop_back();
						cnt++;
					}
					dq.pop_front();
					break;
				}
				else
				{
					while (dq.front() != pos)
					{
						dq.push_back(dq.front());
						dq.pop_front();
						cnt++;
					}
					dq.pop_front();
					break;
				}
			}	
		}
	}
	cout << cnt;

	return 0;
}