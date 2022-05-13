#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

vector <int> dist;
const int INF = 1e9;
vector <vector<pii>> node;


int n, d, c;
int a, b, s;

void dijkstra()
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist.clear();
	dist.resize(n + 1, INF);
	dist[c] = 0;
	pq.push(make_pair(0, c));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		for (int i = 0; i < node[cur].size(); i++)
		{
			int next = node[cur][i].first;
			int nextCost = node[cur][i].second;

			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n >> d >> c;
		node.clear();
		node.resize(n + 1);
		
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			node[b].push_back(make_pair(a, s));
		}
		dijkstra();
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != INF)
			{
				cnt++;
				res = max(res, dist[i]);
			}
		}
		cout << cnt <<" " << res << "\n";
	}
	
	return 0;
}