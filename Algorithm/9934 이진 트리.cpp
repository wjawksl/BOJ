#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int K;
vector<vector<int>> tree;
int res[1030];
int inorderseq[1030];
int idx = 0;
void InOrder(int node)
{
	if (node < (int)pow(2, K))
	{
		InOrder(node * 2);
		res[node] = inorderseq[idx];
		idx++;
		InOrder(node * 2 + 1);
	}
}

int main()
{
	cin >> K;
	int N = pow(2, K) - 1;

	for (int i = 0; i < N; i++)
	{
		cin >> inorderseq[i];
	}
	tree.resize(N + 1);
	
	int k = 1;
	int nextline = 1;
	InOrder(1);
	for (int i = 1; i < N + 1; i++)
	{
		cout << res[i];
		if (i < nextline)
			cout << " ";
		else if(nextline == i)
		{
			cout << "\n";
			k++;
			nextline = pow(2, k) - 1;
		}
	}
	return 0;
}