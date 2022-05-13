#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector <vector<int>> v;
	vector<int> tmp;
	int num,std_idx;
	int N, n, check;
	vector <bool> visited(1005);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &n);
			tmp.push_back(n);
		}
		v.push_back(tmp);
		tmp.clear();
	}
	for (int i = 0; i < N; i++)
	{
		check = 0;
		fill(visited.begin(), visited.end(), false);
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i != k)
				{
					if (v[i][j] == v[k][j])
					{
						if (!visited[k])
						{
							check++;
							visited[k] = true;
						}
					}
				}
			}
		}
		if (i == 0)
		{
			num = check;
			std_idx = i+1;
		}
		else if (num < check)
		{
			num = check;
			std_idx = i+1;
		}
	}
	printf("%d", std_idx);
	return 0;
}