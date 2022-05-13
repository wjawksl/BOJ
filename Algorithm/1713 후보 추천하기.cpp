#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;
bool comp(pii a, pii b)
{
	return a > b;
}
int main()
{
	int N, M, num, picSize = 0;
	vector <pii> pic(101);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (pic[num] != make_pair(0, 0)) pic[num].first++;
		else
		{
			if (picSize < N)
			{
				pic[num] = make_pair(1, i);
				picSize++;
			}
			else
			{
				vector <pii> tmp;
				tmp = pic;
				sort(tmp.begin(), tmp.end(), comp);
				pii target = tmp[N - 1];
				for (int k = 0; k < pic.size(); k++)
				{
					if (pic[k] == target)
					{
						pic[k] = make_pair(0, 0);
						break;
					}
				}
				pic[num] = make_pair(1, i);
			}
		}
	}
	for (int i = 0; i < pic.size(); i++)
	{
		if (pic[i].first != 0) cout << i << " ";
	}
	return 0;
}