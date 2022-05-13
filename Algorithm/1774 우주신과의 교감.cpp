#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef pair<float, float> pff;
typedef pair<int, float> pif;
typedef pair<float, int> pfi;
pff star[105];
bool visited[10005];
priority_queue <pfi, vector <pfi>, greater<pfi>> pq;
vector <vector<pif>> edge(105);
int n;
float x, y, z;
float Prim(int start)
{
	float res = 0;
	visited[start] = true;
	for (int i = 0; i < edge[start].size(); i++)
	{
		pq.push({ edge[start][i].second, edge[start][i].first });
	}
	while (!pq.empty())
	{
		int node = pq.top().second;
		float cost = pq.top().first;
		pq.pop();

		if (!visited[node])
		{
			visited[node] = true;
			res += cost;
			for (int i = 0; i < edge[node].size(); i++)
			{
				if (!visited[edge[node][i].first])
					pq.push({ edge[node][i].second, edge[node][i].first });
			}
		}
	}
	return res;
}
int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		star[i] = { x,y };
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			z = sqrt((star[i].first - star[j].first) * (star[i].first - star[j].first) + (star[i].second - star[j].second) * (star[i].second - star[j].second));
			edge[i].push_back({ j,z });
			edge[j].push_back({ i,z });
		}
	}
	printf("%.2f\n", Prim(1));

	return 0;
}