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
int main()
{
	int N, p1, p2, M, parent, child;
	cin >> N;
	cin >> p1 >> p2;
	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		cin >> parent >> child;
		graph[parent].push_back(child);
	}
	
	return 0;
}