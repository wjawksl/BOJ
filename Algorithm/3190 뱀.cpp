#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int arr[102][102];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int status = 1;
deque <pair<int, int>> snake;

bool move_snake(int status)
{
	if (arr[snake.front().first + dx[status]][snake.front().second + dy[status]] == 1)
	{
		arr[snake.front().first + dx[status]][snake.front().second + dy[status]] = false;
		snake.push_front(make_pair(snake.front().first + dx[status], snake.front().second + dy[status]));
		arr[snake.back().first][snake.back().second] = true;
		snake.pop_back();
	}
	else if (arr[snake.front().first + dx[status]][snake.front().second + dy[status]] == 2)
	{
		arr[snake.front().first + dx[status]][snake.front().second + dy[status]] = false;
		snake.push_front(make_pair(snake.front().first + dx[status], snake.front().second + dy[status]));
	}
	else
		return false;

	return true;
}
int main()
{
	int N, apple_N, x, y, L, sec = 0, move, cnt = 0;
	char dir;
	
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			arr[i][j] = true;
		}
	}

	arr[1][1] = false;
	snake.push_back(make_pair(1, 1));
	cin >> apple_N;

	for (int i = 0; i < apple_N; i++)
	{
		cin >> x >> y;
		arr[x][y] = 2;
	}

	cin >> L;
	cin >> move >> dir;
	cnt++;

	while (true)
	{
		if (sec == move)
		{
			if (dir == 'D')
				status++;
			else
				status--;

			status = (status + 4) % 4;
			cnt++;

			if (cnt <= L)
				cin >> move >> dir;
		}
		if (!move_snake(status))
		{
			sec++;
			break;
		}
		sec++;
	}
	cout << sec;
	return 0;
}