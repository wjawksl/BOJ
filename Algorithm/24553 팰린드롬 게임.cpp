#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long T, N;
int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		if (N < 10) cout << 0;
		else if (N % 10 == 0)
		{
			cout << 1;
		}
		else cout << 0;

		cout << "\n";
	}
	return 0;
}