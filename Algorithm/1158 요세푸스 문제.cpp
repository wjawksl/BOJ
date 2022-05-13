#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue <int> qu;
	int N,K, tmp;

	cin >> N >> K;
	for (int i = 1; i < N + 1; i++)
		qu.push(i);
	cout << "<";
	while (true)
	{
		for (int i = 1; i < K; i++)
		{
			tmp = qu.front();
			qu.pop();
			qu.push(tmp);
		}
		tmp = qu.front();
		qu.pop();

		if (qu.size() == 0)
		{
			cout << tmp << ">";
			break;
		}
		else
			cout << tmp << ", ";
	}
	return 0;
}