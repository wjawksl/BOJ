#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue <int> qu;
	int N, num;
	string cmd;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			qu.push(num);
		}
		else if (cmd == "pop")
		{
			if (qu.empty())
				cout << -1 << "\n";
			else
			{
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		else if (cmd == "size")
			cout << qu.size() << "\n";
		else if (cmd == "empty")
			cout << qu.empty() << "\n";
		else if (cmd == "front")
		{
			if (qu.empty())
				cout << -1 << "\n";
			else
				cout << qu.front() << "\n";
		}
		else if (cmd == "back")
		{
			if (qu.empty())
				cout << -1 << "\n";
			else
				cout << qu.back() << "\n";
		}
	}
	return 0;
}