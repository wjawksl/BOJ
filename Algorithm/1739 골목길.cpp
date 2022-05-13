#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<queue>

/*1. 주의할 점

- 양의 사이클이 아닌, 가중치를 전부 -1로 곱하여 음의 사이클을 구하도록 한다.

- 경로를 어떤 방식으로 저장할 것인가?

- 사이클이 있다고 무조건 -1을 출력하는 것이 아니다. -> 도착지점까지 이동중, 음의 사이클이 존재한다면 -1 출력

2. 구현

- 음의 사이클이 존재하므로 벨만포드 알고리즘을 사용한다.

- Bellman_Ford() 함수를 수행하면서, Child[]에 해당 Node에 도착하기 전까지 최단 거리의 Node번호를 기록한다.

- 음의 사이클이 경로상에 존재하지 않는다면, Child를 통해 이전 Node로 계속 움직이며 답을 구한다.*/
using namespace std;
typedef pair<int, int> pii;

vector <vector <pii>> d(105);
vector<vector<int>> trace(105); // 맨 마지막 노드부터 역추적할 벡터
stack <int> answer;
queue<int> qu;
int N, M;
int child[105], visited[105];
int A, B, C;
const int INF = 987654321;
long long dist[105];
bool flag;
void Bellman_Ford(int start)
{
	flag = false;
	fill(dist, dist + 105, INF);	
	dist[start] = 0;

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < d[i].size(); j++)
			{				
				int next = d[i][j].first;
				int nextCost = d[i][j].second;
				if (dist[i] != INF && dist[next] > dist[i] + nextCost)
				{					
					dist[next] = dist[i] + nextCost;
					child[next] = i;
					if (k == N && visited[next]) flag = true;
				}
			}
		}
	}
}
void BFS(int node)
{
	fill(visited, visited + 105, 0);
	visited[node] = 1;
	
	qu.push(node);
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (int i = 0; i < trace[now].size(); i++)
		{
			int next = trace[now][i];
			if (!visited[next])
			{
				visited[next] = 1;				
				qu.push(next);
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		d[A].push_back({ B, -C }); // 가중치를 음수로 정의
		trace[B].push_back(A);
	}
	
	BFS(N); //BFS를 통해 갈 수 있는 경로만 visited배열에 체크해준다. 갈 수 없는 곳에 존재하는 사이클은 무시!
	Bellman_Ford(1);

	if (flag)
		cout << -1;
	else
	{		
		int node = N;				
		while (node != 1) {
			answer.push(node);
			node = child[node];
		}
		answer.push(1);
		while (!answer.empty()) {
			cout << answer.top() << " ";
			answer.pop();
		}
	}

	return 0;
}