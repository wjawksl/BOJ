#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
typedef pair<int, int> pii;
vector <int> tree;
int idx[500005];
vector <pii> arr;
vector <int> answer;
int B = 1;
void Update(int node, int val)
{
	int idx = node + B - 1;
	tree[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
int IDTSum(int L, int R)
{
	L = L + B - 1; R = R + B - 1;
	int sum = 0;
	while (L <= R)
	{
		if (L % 2 == 1) sum += tree[L];
		if (R % 2 == 0) sum += tree[R];

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return sum;
}
int main()
{
	FIO;
	int N, num;

	cin >> N;
	tree.resize(4 * N);
	answer.resize(N);
	while (B < N)B *= 2;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back({ num,i + 1});		
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		idx[i] = arr[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		int Y = arr.back().second;
		arr.pop_back();
		int cnt = IDTSum(1, Y) + 1;
		answer[Y - 1] = cnt;
		Update(Y, 1);
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;
}