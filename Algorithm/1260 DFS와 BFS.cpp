#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue <int> qu;
bool visited[1005];
vector <vector<int>> graph(20005);

void DFS(int val)
{
	visited[val] = true;
	cout << val << " ";
	for (int i = 0; i < graph[val].size(); i++)
	{
		int next = graph[val][i];
		if (!visited[next])
			DFS(next);
	}
}
void BFS(int val)
{
	visited[val] = 1;
	qu.push(val);

	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		cout << now << " ";
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
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
	int N, M, V, idx, num;
	cin >> N >> M >> V;
	vector <int> tmp;
	for (int i = 0; i < M; i++)
	{
		cin >> idx >> num;
		graph[idx].push_back(num);
		graph[num].push_back(idx);
	}
	for (int i = 1; i < M + 1; i++)
		sort(graph[i].begin(), graph[i].end());
	
	fill(visited, visited + 1005, 0);
	DFS(V);
	fill(visited, visited + 1005, 0);
	cout << "\n";
	BFS(V);
	return 0;
}