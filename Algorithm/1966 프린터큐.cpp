#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int T, N, M, idx;
	
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		queue <int> qu;
		queue <int> tmp;
		
		int docu[100];
		bool check[10];
		int cnt = 0, q_size;
		fill(check, check + 10, false);
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			qu.push(i);
			cin >> docu[i];
			if (!check[docu[i]])
				check[docu[i]] = true;
		}
		idx = 9;
		tmp = qu;
		while (docu[M] != 0)
		{
			if (check[idx])
			{
				qu = tmp;
				q_size = qu.size();
				for (int i = 0; i < q_size; i++)
				{
					if (docu[qu.front()] == idx)
					{
						docu[qu.front()] = 0;
						qu.pop();
						tmp = qu;
						cnt++;
						if (docu[M] == 0)
							break;
					}
					else
					{
						qu.push(qu.front());
						qu.pop();
					}
				}
			}
			idx--;
		}
		cout << cnt << "\n";
	}

	return 0;
}