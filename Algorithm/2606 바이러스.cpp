#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue <int> qu;
bool visited[105];
vector <vector<int>> graph(10000);
int cnt = 0;

int BFS(int val)
{
	visited[val] = 1;
	qu.push(val);

	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		cnt++;
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
	return cnt;
}
int main()
{
	int N, M, idx, num;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> idx >> num;
		graph[idx].push_back(num);
		graph[num].push_back(idx);
	}

	cout << BFS(1) - 1;

	return 0;
}