#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <vector<char>> arr(1000, vector<char>(1000));
int N, M;
char ch;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main()
{
	cin >> N >> M;
	
	for (int i = 1; i <= 3 * N; i++)
	{
		for (int j = 1; j <= 3 * M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= 3 * N; i += 3)
	{
		for (int j = 1; j <= 3 * M; j += 3)
		{
			int x_center = i + 1 , y_center = j + 1;
			if (arr[x_center][y_center] == '#')
				continue;
			arr[x_center][y_center] = '#';
			for (int k = 0; k < 4; k++)
			{
				if (arr[x_center + 2 * dx[k]][y_center + 2 * dy[k]] == '#')
					arr[x_center + dx[k]][y_center + dy[k]] = '#';
			}
		}
	}
	for (int i = 1; i <= 3 * N; i++)
	{
		for (int j = 1; j <= 3 * M; j++)
			cout << arr[i][j];
		cout << "\n";
	}
	
	return 0;
}