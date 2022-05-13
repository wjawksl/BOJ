#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque <int> deq;
	int N, K, M, tmp, cnt = 1;
	bool dir = true;
	cin >> N >> K >> M;
	for (int i = 1; i < N + 1; i++)
		deq.push_back(i);
	
	while (deq.size() != 0)
	{
		for (int i = 1; i < K; i++)
		{
			if (dir)
			{
				tmp = deq.front();
				deq.pop_front();
				deq.push_back(tmp);
			}
			else
			{
				tmp = deq.back();
				deq.pop_back();
				deq.push_front(tmp);
			}
		}
		if (dir)
		{
			cout << deq.front() << "\n";
			deq.pop_front();
		}
		else
		{
			cout << deq.back() << "\n";
			deq.pop_back();
		}

		if (cnt % M == 0 && cnt != 0)
		{
			if (dir)
				dir = false;
			else
				dir = true;
		}
		cnt++;
	}
	return 0;
}