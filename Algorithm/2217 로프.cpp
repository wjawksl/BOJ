#include<iostream>
#include<algorithm>

using namespace std;

int rope[100005];
bool comp(int n1, int n2)
{
	if (n1 > n2)
		return true;
	else
		return false;
}
int main()
{
	int N, res, weight;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> rope[i];
	sort(rope, rope + 100005, comp);

	res = rope[0];
	for (int i = 1; i < N; i++)
	{
		weight = rope[i] * (i + 1);
		if (res < weight)
			res = weight;
	}
	cout << res << "\n";
	return 0;
}