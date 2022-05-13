#include<iostream>
#include<algorithm>

using namespace std;

int game[155][1];
int main()
{
	int N,K , now, next,cnt = 0,tmp;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> game[i][0];
	now = 0;
	next = game[now][0];
	while (next != -1 && now != K)
	{
		cnt++;
		game[now][0] = -1;
		now = next;
		next = game[now][0];
	}
	if (now == K)
		cout << cnt;
	else
		cout << -1;
	
	return 0;
}