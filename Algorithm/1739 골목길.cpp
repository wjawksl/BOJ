#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<queue>

/*1. ������ ��

- ���� ����Ŭ�� �ƴ�, ����ġ�� ���� -1�� ���Ͽ� ���� ����Ŭ�� ���ϵ��� �Ѵ�.

- ��θ� � ������� ������ ���ΰ�?

- ����Ŭ�� �ִٰ� ������ -1�� ����ϴ� ���� �ƴϴ�. -> ������������ �̵���, ���� ����Ŭ�� �����Ѵٸ� -1 ���

2. ����

- ���� ����Ŭ�� �����ϹǷ� �������� �˰����� ����Ѵ�.

- Bellman_Ford() �Լ��� �����ϸ鼭, Child[]�� �ش� Node�� �����ϱ� ������ �ִ� �Ÿ��� Node��ȣ�� ����Ѵ�.

- ���� ����Ŭ�� ��λ� �������� �ʴ´ٸ�, Child�� ���� ���� Node�� ��� �����̸� ���� ���Ѵ�.*/
using namespace std;
typedef pair<int, int> pii;

vector <vector <pii>> d(105);
vector<vector<int>> trace(105); // �� ������ ������ �������� ����
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
		d[A].push_back({ B, -C }); // ����ġ�� ������ ����
		trace[B].push_back(A);
	}
	
	BFS(N); //BFS�� ���� �� �� �ִ� ��θ� visited�迭�� üũ���ش�. �� �� ���� ���� �����ϴ� ����Ŭ�� ����!
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