#include<iostream>
#include<algorithm>
#include<vector>

#define INF 1e9
using namespace std;
int city[105][105];
int N, M;

void Floyd_Warshall()
{
	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (city[i][j] > city[i][k] + city[k][j])
					city[i][j] = city[i][k] + city[k][j];
			}
		}
	}
}
int main()
{
	int a, b, c;
	cin >> N >> M;
	fill(&city[0][0], &city[104][105], INF);
	for (int i = 0; i < 105; i++)
	{
		city[i][i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if(city[a][b] > c) city[a][b] = c;
	}
	Floyd_Warshall();
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (city[i][j] == INF) cout << 0 << " ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}