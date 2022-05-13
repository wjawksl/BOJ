#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int N,cnt = 0;
bool visited[50];
int parent[50];
int node, del, root;
vector<vector<int>> tree;
void Delete_node(int node)
{
	for (int i = 0; i < tree[node].size(); i++)
	{
		Delete_node(tree[node][i]);
	}
	tree[node].resize(0);
}
void DFS(int val)
{
	visited[val] = true;
	if (tree[val].size() == 0) cnt++;
	
	for (int i = 0; i < tree[val].size(); i++)
	{
		int next = tree[val][i];
		if (!visited[next])
			DFS(next);
	}
}
int main()
{
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> node;
		if (node == -1)
		{
			parent[i] = -1;
			root = i;
			continue;
		}
		parent[i] = node;
		tree[node].push_back(i);
	}
	cin >> del;
	int del_p = parent[del];
	if (del_p != -1)
	{
		for (int i = 0; i < tree[del_p].size(); i++)
		{
			if (tree[del_p][i] == del)
				tree[del_p].erase(tree[del_p].begin() + i);
		}
	}
	
	Delete_node(del);
	if (del == root)
		cout << 0;
	else
	{
		DFS(root);
		cout << cnt;
	}
	return 0;
}