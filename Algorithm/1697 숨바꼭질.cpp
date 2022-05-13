#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

queue <pii> qu;
bool visited[200005];
int N, K;
int BFS(pii pN)
{
	visited[pN.first] = 1;
	qu.push(pN);

	while (!qu.empty())
	{
		pii now = qu.front();
		qu.pop();
		for (int i = 0; i < 3; i++)
		{
			int next;
			if (i == 0)
				next = now.first - 1;
			else if (i == 1)
				next = now.first + 1;
			else
				next = now.first * 2;

			if (next < 0 || next > 100000)
				continue;
			if (!visited[next])
			{
				if (next == K)
					return now.second + 1;
				visited[next] = 1;
				qu.push({next, now.second + 1});
			}
		}
	}
	return -1;
}
int main()
{
	cin >> N >> K;
	pii pN = { N,0 };
	
	if (N == K)
		cout << 0;
	else
		cout << BFS(pN);
	return 0;
}