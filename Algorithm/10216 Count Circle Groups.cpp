#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef pair<pair<int, int>, float> piif;
int parent[3005];
int sizes[3005];
int N, x, y;
float R;
bool flag = false;

int Find(int n)
{
	if (parent[n] == n) return n;
	else return parent[n] = Find(parent[n]);
}

void UnionBySize(int n1, int n2)
{
	n1 = Find(n1);
	n2 = Find(n2);

	if (n1 != n2)
	{
		if (sizes[n1] < sizes[n2]) swap(n1, n2);
		sizes[n1] += sizes[n2];
		parent[n2] = n1;
	}
}

int main()
{
	FIO;
	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++)
	{
		cin >> N;
		vector <piif> P;
		fill(parent, parent + 3005, 0);
		fill(sizes, sizes + 3005, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y >> R;
			P.push_back({ {x,y},R });
			parent[i] = i;
			sizes[i] = 1;
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				float d = sqrt((P[i].first.first - P[j].first.first) * (P[i].first.first - P[j].first.first) + (P[i].first.second - P[j].first.second) * (P[i].first.second - P[j].first.second));
				if (d <= P[i].second + P[j].second) UnionBySize(i, j);
			}
		}
		map<int, int> m;
		for (int i = 0; i < N; i++)
		{
			m.insert({ Find(i), 0 });
		}
		cout << m.size() << "\n";
	}
	return 0;
}