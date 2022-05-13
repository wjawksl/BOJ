#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector <vector <int>> v(32005);
bool visited[32005];
queue <int> qu;
int len[32005];
void BFS()
{
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			len[next]--;
			if (len[next] == 0)
				qu.push(next);
		}
	}
}

int main()
{
	int N, M, A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		len[B]++;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (len[i] == 0)
			qu.push(i);
	}
	BFS();
	
	return 0;
}