#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
struct Fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
};
vector<vector<vector<Fireball>>> map(55, vector<vector<Fireball>>(55, vector<Fireball>()));
int N, M, K, total;
bool check(int r, int c)
{
	return ((1 <= r && 1 <= c) && (r <= N && c <= N));
}
int main()
{
	int r, c, m, s, d;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> m >> s >> d;		
		map[r][c].push_back({ r,c,m,s,d });
	}
	while (K != 0)
	{
		vector<vector<vector<Fireball>>> movedMap(55, vector<vector<Fireball>>(55, vector<Fireball>()));
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				for (int k = 0; k < map[i][j].size(); k++)
				{
					Fireball fb = map[i][j][k];
					
					fb.r = fb.r + dx[fb.d] * fb.s;
					fb.c = fb.c + dy[fb.d] * fb.s;

					if (!check(fb.r, fb.c))
					{
						if (fb.r > N) fb.r = fb.r % N;
						if (fb.r < 1) fb.r = N - abs(fb.r) % N;
						if (fb.c > N) fb.c = fb.c % N;
						if (fb.c < 1) fb.c = N - abs(fb.c) % N;						
					}
								
					movedMap[fb.r][fb.c].push_back(fb);
				}
			}
		}
		map = movedMap;
		total = 0;
		
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				int size = map[i][j].size();
				r = 0; c = 0; m = 0; s = 0; d = 0;
				if (size == 1) total += map[i][j][0].m;
				else if (size >= 2)
				{
					int tmp = 0;
					for (int k = 0; k < size; k++)
					{
						tmp += map[i][j][k].d % 2;
						m += map[i][j][k].m;
						s += map[i][j][k].s;
					}
					m = m / 5; s = s / size;
					map[i][j].clear();
					if (m != 0)
					{
						total += m * 4;
						if (tmp == 0 || tmp == size)
						{
							for (int k = 0; k < 4; k++)
								map[i][j].push_back({ i,j,m,s,k * 2 });
						}
						else
						{
							for (int k = 0; k < 4; k++)
								map[i][j].push_back({ i,j,m,s,k * 2 + 1 });
						}
					}
				}
			}
		}
		K--;
		
	}
	cout << total << "\n";
	return 0;
}