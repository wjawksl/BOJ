#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[50][9];
int tmp[50][9];
vector <int> base(3);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, idx = 0, out, score, j;
	int max_score = 0;
	vector <int> tmp = { 1,2,3,4,5,6,7,8 };
	vector <int> id;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}
	do
	{
		score = 0;
		j = 0;
		id = tmp;
		id.emplace(id.begin() + 3, 0);
		
		for (int i = 0; i < N; i++)
		{
			fill(base.begin(), base.end(), false);
			out = 0;
			while (out < 3)
			{
				if (j > 8)
					j = 0;

				if (arr[i][id[j]] == 0)
				{
					out++;
					j++;
					continue;
				}
				for (int k = 2; k >= 0; --k)
				{
					if (base[k])
					{
						if (k + arr[i][id[j]] >= 3) ++score;
						else base[k + arr[i][id[j]]] = true;
						base[k] = false;
					}
				}
				if (arr[i][id[j]] == 4) ++score;
				else base[arr[i][id[j]] - 1] = true;
				
				j++;
			}
		}
		max_score = max(score, max_score);
		
	} while (next_permutation(tmp.begin(), tmp.end()));


	cout << max_score;
	return 0;
}