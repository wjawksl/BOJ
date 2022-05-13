#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, pair<int,int>> piii;

vector <vector<int>> map;
priority_queue <piii, vector<piii>, greater<piii>> pq;
vector <vector<int>> breakCnt;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int status;
string str;
const int INF = 1e9;

void dijkstra()
{
	breakCnt.resize(M, vector<int>(N,INF));
	breakCnt[0][0] = 0;
	
	pq.push(make_pair(0, make_pair(0,0)));
	while (!pq.empty())
	{
		int cnt = pq.top().first;
		pair<int,int> cur = pq.top().second;
		
		pq.pop();
		for (int d = 0; d < 4; d++)
		{
			pair<int, int> next = make_pair(cur.first + dx[d], cur.second + dy[d]);
			if ((0 <= next.first && next.first < M) && (0 <= next.second && next.second < N))
			{
				if (breakCnt[next.first][next.second] > breakCnt[cur.first][cur.second] + 1)
				{
					if (map[next.first][next.second] == 1)
						breakCnt[next.first][next.second] = breakCnt[cur.first][cur.second] + 1;
					else
						breakCnt[next.first][next.second] = breakCnt[cur.first][cur.second];

					pq.push(make_pair(breakCnt[next.first][next.second], next));
				}
			}
		}
	}
}
int main()
{
	FIO;
	cin >> N >> M;
	map.resize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			map[i].push_back(str[j] - '0');
		}
	}
	dijkstra();
	cout << breakCnt[M - 1][N - 1];
	return 0;
}