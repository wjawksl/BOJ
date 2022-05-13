#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector <vector<int>> node(505, vector<int>());
vector <vector<int>> order(505, vector<int>());
queue<int> qu;
int cost[505];
int dp[505];
int len[505];
int N;
void PhaseSort()
{
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i];
			len[next]--;
			dp[next] = max(dp[next], dp[now] + cost[next]);
			if (len[next] == 0) qu.push(next);
		}
	}	
}
int main()
{
	int tmp;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> cost[i];
		cin >> tmp;
		if (tmp != -1)
		{
			node[tmp].push_back(i);
			order[i].push_back(tmp);
			len[i]++;
			while (true)
			{
				cin >> tmp;
				if (tmp == -1) break;

				node[tmp].push_back(i);
				order[i].push_back(tmp);
				len[i]++;
			}
		}		
	}	
	for (int i = 1; i < N + 1; i++)
	{
		if (len[i] == 0)
		{
			qu.push(i);
			dp[i] = cost[i];
		}			
	}
	PhaseSort();
	for (int i = 1; i < N + 1; i++)
	{
		cout << dp[i] << "\n";
	}
	return 0;
}