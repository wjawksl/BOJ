#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector <vector<int>> tree;
int visited[1005];
int visitedRoot[1005];
int check[1005];
bool End = true;
int u, v = 0;
int parent[1005];
bool flag;
void InOrder(int now)
{
	if (!visited[now])
	{
		visited[now] = 1;
		for (int i = 0; i < tree[now].size(); i++)
		{
			InOrder(tree[now][i]);
		}
	}
	else flag = false;
}
int main()
{
	int cnt = 0, tmp;
	while (End)
	{
		int i = 0;
		flag = true;
		cnt++;
		tree.clear();
		tree.resize(1005);
		fill(parent, parent + 1005, 0);

		int node, root;
		while (true)
		{
			cin >> u >> v;
			if (u == -1 && v == -1)
			{
				End = false;
				break;
			}
			if (u == 0 && v == 0) break;

			tree[u].push_back(v);
			if (parent[v] != 0)
			{
				flag = false;				
			}
			parent[v] = u;
		}
		if (End == false) break;		
		for (int i = 1; i < 1005; i++)
		{
			node = i;
			fill(visitedRoot, visitedRoot + 1005, 0);
			while (parent[node] != 0)
			{
				if (visitedRoot[node])
				{
					flag = false;
					break;
				}			
				visitedRoot[node] = 1;
				node = parent[node];			
			}
			if (!flag) break;
			else check[node]++;
		}
		int max = 0;
		for (int i = 1; i < 1005; i++)
		{
			if (max < check[i])
			{
				max = check[i];
				root = i;
			}
		}
		if (flag)
		{
			fill(visited, visited + 1005, 0);
			InOrder(root);
			if(flag)
				cout << "Case " << cnt << " is a tree." << "\n";
			else
				cout << "Case " << cnt << " is not a tree." << "\n";
		}
		else
			cout << "Case " << cnt << " is not a tree." << "\n";

	}

	return 0;
}