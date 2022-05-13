#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector <int> p = { 1,1,1,1,1,1,1,0,0 };
	vector <int> dwarf;
	vector <int> tmp;
	int height, sum;
	bool flag;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height);
		dwarf.push_back(height);
	}
	while (true)
	{
		flag = false;
		sum = 0;
		for (int i = 0; i < 9; i++)
		{
			if (p[i])
			{
				sum += dwarf[i];
				tmp.push_back(dwarf[i]);
			}
		}
			if (sum == 100)
			{
				flag = true;
				break;
			}
			if (flag) break;

			next_permutation(p.begin(), p.end());
			tmp.clear();

	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++)
	{
		printf("%d\n", tmp[i]);
	}
	return 0;
}
