#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector <int> sushi;
int visited[3005];
int cnt;
int answer = 0;
int main()
{
	FIO;
	int N, d, k, c;
	
	cin >> N >> d >> k >> c;
	sushi.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> sushi[i];
	}
	for (int i = 0; i < N; i++)
	{
		int idx;
		
		fill(visited, visited + 3005, 0);
		visited[c] = 1;
		cnt = 1;
		for (int j = i; j < i + k; j++)
		{
			idx = j % sushi.size();
			if (!visited[sushi[idx]])
			{
				visited[sushi[idx]] = 1;
				cnt++;
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}