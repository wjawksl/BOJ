#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue <int> card;
	int N, tmp;

	cin >> N;
	for (int i = 1; i < N + 1; i++)
		card.push(i);

	while (card.size() != 1)
	{
		card.pop();
		tmp = card.front();
		card.pop();
		card.push(tmp);
	}
	cout << card.front();
	return 0;
}