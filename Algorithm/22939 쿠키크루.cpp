#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

vector<string> map;
vector<string> job = { "Assassin" ,"Healer" , "Mage" , "Tanker"};
int visited[5];
vector<pii> W;
vector<pii> C;
vector<pii> B;
vector<pii> J;
vector<int> v;
string ans;
pii home, dest;
int N, dist, job_idx, max_dist = INF;
void Permutation(vector<pii> topping)
{
	if (v.size() == 3)
	{
		pii now = home;
		dist = 0;
		for (int i = 0; i < v.size(); i++)
		{
			dist += abs(now.first - topping[v[i]].first) + abs(now.second - topping[v[i]].second);
			now = topping[v[i]];
		}
		dist += abs(now.first - dest.first) + abs(now.second - dest.second);		
		if (dist < max_dist)
		{
			ans = job[job_idx];
			max_dist = dist;
		}
	}
	for (int i = 0; i < topping.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(i);
			Permutation(topping);
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main()
{
	string str;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		map.push_back(str);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'H') home = { i,j };
			else if (map[i][j] == '#') dest = { i,j };
			else if (map[i][j] == 'J') J.push_back({ i,j });
			else if (map[i][j] == 'C') C.push_back({ i,j });
			else if (map[i][j] == 'B') B.push_back({ i,j });
			else if (map[i][j] == 'W') W.push_back({ i,j });
		}
	}
	job_idx = 0; Permutation(J);
	job_idx = 1; Permutation(C);
	job_idx = 2; Permutation(B);
	job_idx = 3; Permutation(W);

	cout << ans;
	return 0;
}