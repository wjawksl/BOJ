#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	vector <int> v;
	vector <int> log(10010);
	int T,N, L, lod;

	scanf("%d", &T);
	for (int a = 0; a < T; a++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &L);
			v.push_back(L);
		}
		int start_idx = 0, end_idx = v.size() - 1;

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2) log[end_idx--] = v[i];
			else log[start_idx++] = v[i];
		}
		for (int i = 0; i < v.size()-1; i++)
		{
			if (i == 0) lod = abs(log[1] - log[0]);

			lod = max(lod, abs(log[i + 1] - log[i]));
		}
		printf("%d\n", lod);
		v.clear();
		fill(log.begin(), log.end(), 0);
	}
	
	return 0;
}