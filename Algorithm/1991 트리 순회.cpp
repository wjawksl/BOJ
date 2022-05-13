#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int N;
bool visited[50];
char node, leftnode, rightnode;
vector<vector<char>> tree;

void PreOrder(char val)
{
	if (val != '.')
	{
		int cur = val - 'A';
		visited[cur] = true;

		cout << val;
		PreOrder(tree[cur][0]);
		PreOrder(tree[cur][1]);
	}
}
void InOrder(char val)
{
	if (val != '.')
	{
		int cur = val - 'A';
		visited[cur] = true;

		InOrder(tree[cur][0]);
		cout << val;
		InOrder(tree[cur][1]);
	}
}
void PostOrder(char val)
{
	if (val != '.')
	{
		int cur = val - 'A';
		visited[cur] = true;

		PostOrder(tree[cur][0]);
		PostOrder(tree[cur][1]);
		cout << val;
	}
	
}
int main()
{
	int idx;
	cin >> N;
	tree.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> node >> leftnode >> rightnode;
		idx = node - 'A';
		
		tree[idx].push_back(leftnode);
		tree[idx].push_back(rightnode);
	}
	
	PreOrder('A');
	fill(visited, visited + 50, 0);
	cout << "\n";
	InOrder('A');
	fill(visited, visited + 50, 0);
	cout << "\n";
	PostOrder('A');
	return 0;
}