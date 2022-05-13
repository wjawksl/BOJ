#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, cnt = 0;
int check[15][15];
void checkFunc(int row, int col, int num)
{
	check[row][col] += num;
	for (int i = 1; i < N; i++)
	{
		int nextRow, nextCol;

		if (col + i < N)
		{
			nextCol = col + i;
			check[row][nextCol] += num;
			if (row - i >= 0)
			{
				nextRow = row - i;
				check[nextRow][nextCol] += num;
			}
			if (row + i < N)
			{
				nextRow = row + i;
				check[nextRow][nextCol] += num;
			}

		}
		if (col - i >= 0)
		{
			nextCol = col - i;
			check[row][nextCol] += num;
			if (row - i >= 0)
			{
				nextRow = row - i;
				check[nextRow][nextCol] += num;
			}
			if (row + i < N)
			{
				nextRow = row + i;
				check[nextRow][nextCol] += num;
			}
		}
		if (row - i >= 0)
		{
			nextRow = row - i;
			check[nextRow][col] += num;
		}
		if (row + i < N)
		{
			nextRow = row + i;
			check[nextRow][col] += num;
		}
	}
}
void NQueen(int row, int col)
{	
	if (row == N)
	{
		cnt++;
		return;
	}	
	if (check[row][col] == 0)
	{
		checkFunc(row, col, 1);
		for (int j = 0; j < N; j++)
		{
			if (check[row + 1][j] == 0)
			{
				NQueen(row + 1, j);
				if (row + 1 == N) break;
				checkFunc(row + 1, j, -1);
			}				
		}		
	}
}
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		fill(&check[0][0], &check[14][15], 0);
		NQueen(0, i);
	}
	cout << cnt << "\n";
	return 0;
}