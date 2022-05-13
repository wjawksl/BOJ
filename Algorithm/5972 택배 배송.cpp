#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

vector <int> dist;
const int INF = 1e9;
vector <vector<pii>> node;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int N, M;
int A_i, B_i, C_i;

void dijkstra()
{
	dist.resize(N + 1, INF);
	dist[1] = 0;
	pq.push(make_pair(0, 1));
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
	cin >> N >> M;
	node.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> A_i >> B_i >> C_i;
		node[A_i].push_back(make_pair(B_i, C_i));
		node[B_i].push_back(make_pair(A_i, C_i));
	}
	dijkstra();
	cout << dist[N];
	return 0;
}