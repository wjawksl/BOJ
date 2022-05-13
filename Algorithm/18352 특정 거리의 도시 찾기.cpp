#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int, int> pii;

vector <vector<pii>> city;
priority_queue <pii, vector<pii>, greater<pii>> pq;
vector <int > dist;
int N, M, K, X;
int A, B;
const int INF = 1e9;
void dijkstra()
{
	dist.resize(N + 1, INF);
	dist[X] = 0;
	pq.push(make_pair(0, X));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = city[cur][i].second;

			if (dist[next] > nextCost + dist[cur])
			{
				dist[next] = nextCost + dist[cur];
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	cin >> N >> M >> K >> X;
	city.resize(N + 1);
	
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		city[A].push_back(make_pair(B, 1));
	}
	dijkstra();
	for (int i = 1; i < N + 1; i++)
	{
		if (dist[i] == K)
		{
			cout << i << "\n";
			flag = true;
		}	
	}
	if (!flag)
		cout << -1;
	return 0;
}