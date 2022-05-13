#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct VI {
	int val;
	int x;
	int y;
};
struct comp {
	bool operator()(VI a, VI b) {
		return a.val > b.val;
	}
};
queue <VI> qu;
priority_queue <VI, vector<VI>, comp> pq;
vector <vector<int>> virus(1005, vector<int>(1005));

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, K, S, X, Y, num, cnt;

void BFS()
{
	if (S == 0) return;
	cnt = 0;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (virus[i][j] != 0)
			{
				pq.push({ virus[i][j] , i,j });
			}
		}
	}
	while (!pq.empty())
	{
		qu.push(pq.top());
		pq.pop();
	}
	int num_const = qu.size(), num = 0;
	while (!qu.empty())
	{
		VI now = qu.front();
		qu.pop();
		num++;
		for (int i = 0; i < 4; i++)
		{
			int nextdx = now.x + dx[i];
			int nextdy = now.y + dy[i];
			if ((0 < nextdx && nextdx <= N) && (0 < nextdy && nextdy <= N))
			{
				if (virus[nextdx][nextdy] == 0)
				{
					virus[nextdx][nextdy] = virus[now.x][now.y];
					qu.push({ virus[nextdx][nextdy], nextdx, nextdy });
				}
			}
		}
		if (num_const == num)
		{
			cnt++;
			if (cnt == S) return;
			num_const = qu.size();
			num = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cin >> virus[i][j];
	}
	cin >> S >> X >> Y;
	BFS();
	cout << virus[X][Y];
	return 0;
}