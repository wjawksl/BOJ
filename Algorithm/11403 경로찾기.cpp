#include<iostream>
#include<algorithm>

using namespace std;

int N;
int edge[101][101];
int main()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> edge[i][j];
		}
	}

	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (edge[i][k] && edge[k][j]) edge[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cout << edge[i][j]<< " ";
		}
		cout << "\n";
	}
	return 0;
}