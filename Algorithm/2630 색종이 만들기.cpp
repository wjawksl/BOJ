#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int white, blue;
int cp[130][130];

void get_cnt(int r, int c, int size)
{
	int color = cp[r][c];
	for (int i = r; i < r + size; i++)
	{
		for (int j = c; j < c + size; j++)
		{
			if (cp[i][j] != color)
			{
				get_cnt(r, c, size / 2); // �� 1��и�
				get_cnt(r, c + (size / 2), size / 2); // �� 2��и�
				get_cnt(r + (size / 2), c, size / 2); // �� 3��и�
				get_cnt(r + (size / 2), c + (size / 2), size / 2); // �� 4��и�
				return;
			}
		}
	}
	if (color == 1) blue++;	
	else white++;		
}
int main()
{
	int N,num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cp[i][j];
		}
	}
	get_cnt(0, 0, N);
	cout << white << "\n" << blue;
	return 0;
}