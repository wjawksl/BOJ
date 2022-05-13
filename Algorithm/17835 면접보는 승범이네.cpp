#include<iostream>
#include<algorithm>
#include<queue>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector <ll> dist;
vector <vector<pll>> edge;
priority_queue <pll, vector<pll>, greater<pll>> pq;
int visited[100005];
const ll INF = 1e15;
int N, M, K;
int U, V, C, A;
void dijkstra()
{			
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;
		visited[cur] = 1;

		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].first;
			int nextCost = edge[cur][i].second;

			if (dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main()
{
	FIO;

	cin >> N >> M;
	cin >> K;
	edge.resize(N + 1);
	dist.resize(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		cin >> U >> V >> C;
		edge[V].push_back({ U, C }); // ������ ����������� �Ÿ��� ���ϱ� ���� ��θ� ������ �ִ´�.
	}
	for (int i = 0; i < K; i++) // ���� ����� �������� ã�� ���� ��� �������� pq�� ����! >> ���� ����� �����常 ���ŵȴ�.
	{
		cin >> A;
		dist[A] = 0;
		pq.push({ 0, A });
	}
	dijkstra();

	ll Max = 0, idx = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (dist[i] > Max)
		{
			Max = dist[i];
			idx = i;
		}
	}
	cout << idx << "\n" << Max;
	
	return 0;
}