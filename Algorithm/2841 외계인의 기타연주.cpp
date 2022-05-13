#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <vector <int>> v(7);
int main()
{
	int N, P, n, p, cnt = 0;

	cin >> N >> P;
	for (int i = 0; i < N; i++)
	{
		cin >> n >> p;
		if (!v[n].empty())
		{
			if (v[n].back() == p)
				continue;
			if (v[n].back() > p)
			{
				while (v[n].back() > p)
				{
					v[n].pop_back();
					cnt++;
					if (v[n].empty())
						break;
				}
			}
			if (!v[n].empty() && v[n].back() == p)
				continue;
		}
		v[n].push_back(p);
		cnt++;
	}
	cout << cnt;
	return 0;
}