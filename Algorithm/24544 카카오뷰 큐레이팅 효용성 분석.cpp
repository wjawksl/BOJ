#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, total, myView, a;
vector<int> interest;
int main()
{
	cin >> N;

	interest.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> interest[i];
	}
	for (int i = 0; i < N; i++)
	{	
		total += interest[i];

		cin >> a;

		if (!a) myView += interest[i];
	}

	cout << total << "\n" << myView;
	return 0;
}