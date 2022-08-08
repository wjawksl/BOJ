#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector <int> sushi;
deque<int> window;

int visited[3005];
int answer = 0, cnt = 0;
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
	visited[c]++;
	cnt++;
	for (int i = 0; i < k; i++)
	{	
		if (!visited[sushi[i]])
		{
			window.push_back(sushi[i]);
			cnt++;
		}
		visited[sushi[i]]++;	
	}
	answer = max(answer, cnt);

	for (int i = 0; i < N; i++)
	{
		int s = i, e = (i + k) % N;
		
		if (visited[sushi[i]] == 1) cnt--;
		visited[sushi[i]]--;
		window.pop_front();

		if (visited[sushi[e]] == 0) cnt++;
		visited[sushi[e]]++;
		window.push_back(sushi[e]);
		
		answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}