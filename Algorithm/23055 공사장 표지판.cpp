#include<iostream>
#include<algorithm>

using namespace std;

char sign[25][25];
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 || j == 0 || i == j || i == N- 1 || j == N - 1 || (i + j) == N - 1 )
				sign[i][j] = '*';
			else sign[i][j] = ' ';

			cout << sign[i][j];
		}
		cout << "\n";
	}
	return 0;
}