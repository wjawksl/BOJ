#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> hater;
vector<int> blue, white;
int visited[105];
int n;
void dfs(int node, int team) {
	visited[node] = team;
	for (int i = 0; i < hater[node].size(); i++) {
		int next = hater[node][i];

		if(!visited[next]) dfs(next, -team);			
	}
}
int main() {

	int a, b;
	cin >> n;

	hater.resize(n + 1);

	for (int i = 1; i < n + 1; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			hater[i].push_back(b);
			hater[b].push_back(i);
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (visited[i] == 1) blue.push_back(i);
		else white.push_back(i);
	}
	cout << blue.size() << "\n";
	for (int i = 0; i < blue.size(); i++) {
		cout << blue[i] << " ";
	}
	cout << "\n";

	cout << white.size() << "\n";
	for (int i = 0; i < white.size(); i++) {
		cout << white[i] << " ";
	}
	return 0;
}