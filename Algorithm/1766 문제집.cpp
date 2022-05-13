#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector <vector <int>> v(32005);
bool visited[32005];
priority_queue <int, vector<int>, greater<int>> pq;
int len[32005];

void BFS()
{
	
	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			len[next]--;
			if (len[next] == 0)
				pq.push(next);
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
			pq.push(i);
	}
	BFS();

	return 0;
}