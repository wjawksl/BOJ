#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector <vector <int>> v(1005);
vector <int> len(1005);
queue <int> qu;
int D[1005]; // �ǹ� �Ǽ� �� �ҿ�Ǵ� �ð�
int route[1005]; // �ش� �������� �ɸ��� �ð�
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
			if (route[next] < route[now] + D[next]) // ���ܰ��� �ǹ����� ��� �������� �ϹǷ� 
				route[next] = route[now] + D[next]; // �����ϸ鼭 �ɸ� �ð��� �ִ����� ����
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
			len[Y]++; //�������� ����
		}
		cin >> W;
		for (int i = 1; i < N + 1; i++)
		{
			if (len[i] == 0)
			{
				qu.push(i);
				route[i] = D[i]; // ������ �ʱ�ȭ
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