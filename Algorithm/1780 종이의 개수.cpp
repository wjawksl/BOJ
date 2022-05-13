#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
vector <vector<int>> p;

void get_cnt(int r_idx, int c_idx, int size)
{
	int val = p[r_idx][c_idx];
	for (int i = r_idx; i < r_idx + size; i++)
	{
		for (int j = c_idx; j < c_idx + size; j++)
		{
			if (p[i][j] != val)
			{
				get_cnt(r_idx, c_idx, size / 3);
				get_cnt(r_idx, c_idx + (size / 3), size / 3);
				get_cnt(r_idx, c_idx + (size / 3) * 2, size / 3);

				get_cnt(r_idx + (size / 3), c_idx, size / 3);
				get_cnt(r_idx + (size / 3), c_idx + (size / 3), size / 3);
				get_cnt(r_idx + (size / 3), c_idx + (size / 3) * 2, size / 3);

				get_cnt(r_idx + (size / 3) * 2, c_idx, size / 3);
				get_cnt(r_idx + (size / 3) * 2, c_idx + (size / 3), size / 3);
				get_cnt(r_idx + (size / 3) * 2, c_idx + (size / 3)*2, size / 3);
				return;
			}
		}
	}
	if (val == -1)
		cnt1++;
	else if (val == 0)
		cnt2++;
	else
		cnt3++;
}
int main()
{
	int N, num;
	vector <int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &num);
			v.push_back(num);
		}
		p.push_back(v);
		v.clear();
	}
	get_cnt(0, 0, N);
	printf("%d\n%d\n%d", cnt1, cnt2, cnt3);
	return 0;
}