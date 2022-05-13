#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector <vector <int>> v(1005);
vector <int> len(1005);
queue <int> qu;
int D[1005]; // 건물 건설 시 소요되는 시간
int route[1005]; // 해당 노드까지의 걸리는 시간
int W;

void BFS()
{
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (route[next] < route[now] + D[next]) // 전단계의 건물들이 모두 지어져야 하므로 
				route[next] = route[now] + D[next]; // 갱신하면서 걸린 시간의 최댓값으로 설정
			len[next]--;
			if (len[next] == 0)
				qu.push(next);
		}
	}
}

int main()
{
	int T, N, K, X, Y;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		
		cin >> N >> K;
		for (int i = 1; i < N + 1; i++) {
			cin >> D[i];
		}

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			v[X].push_back(Y);
			len[Y]++; //진입차수 설정
		}
		cin >> W;
		for (int i = 1; i < N + 1; i++)
		{
			if (len[i] == 0)
			{
				qu.push(i);
				route[i] = D[i]; // 시작점 초기화
			}
		}
		BFS();
		cout << route[W] << "\n";

		for (int i = 1; i < N + 1; i++)
			v[i].clear();
		fill(D, D + 1005, 0);
		fill(route, route + 1005, 0);
		fill(len.begin(), len.end(), 0);
	}
	return 0;
}