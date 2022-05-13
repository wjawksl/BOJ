#include<iostream>
#include<algorithm>

using namespace std;

int room[22][22];
int student[20*20+5][4];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0 ,-1 ,0 };
int main()
{
	int N, stu, a, b, c, d, x, y;
	int check, Max = -1, emp, MaxEmp = -1;
	cin >> N;
	for (int i = 1; i < N * N + 1; i++)
	{
		cin >> stu;
		cin >> a >> b >> c >> d;
		student[stu][0] = a; student[stu][1] = b;
		student[stu][2] = c; student[stu][3] = d;
				
		Max = -1;  MaxEmp = -1;
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < N + 1; k++)
			{
				check = 0; emp = 0;
				if (room[j][k] == 0)
				{					
					for (int l = 0; l < 4; l++)
					{
						int nextX = j + dx[l], nextY = k + dy[l];
						if ((0 < nextX && nextX <= N) && (0 < nextY && nextY <= N))
						{
							if (room[nextX][nextY] == 0) emp++;
							for (int m = 0; m < 4; m++)
							{
								if (room[nextX][nextY] == student[stu][m]) check++;
							}
						}
					}
					if (check > Max)
					{
						Max = check;
						MaxEmp = emp;
						x = j; y = k;
					}
					else if (check == Max)
					{
						if (emp > MaxEmp)
						{
							MaxEmp = emp;
							x = j; y = k;
						}
					}
				}
			}
		}
		room[x][y] = stu;
	}
	int sum = 0;
	int score[5] = { 0,1,10,100,1000 };
	for (int j = 1; j < N + 1; j++)
	{
		for (int k = 1; k < N + 1; k++)
		{
			check = 0;
			for (int l = 0; l < 4; l++)
			{
				int nextX = j + dx[l], nextY = k + dy[l];
				if ((0 < nextX && nextX <= N) && (0 < nextY && nextY <= N))
				{
					for (int m = 0; m < 4; m++)
					{
						if (room[nextX][nextY] == student[room[j][k]][m]) check++;
					}
				}
			}
			sum += score[check];
		}
	}
	cout << sum;
	return 0;
}