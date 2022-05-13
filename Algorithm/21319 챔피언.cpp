#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <int> strong(200001);
vector <int> tmp;
vector <int> res;
bool check[200001];
int N, r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	check[N] = 1;
	for (int i = 0; i < N; i++)
		cin >> strong[i];

	
	for (int i = N - 1; i >= 0; i--)
	{
		if (strong[i] > strong[i - 1])
		{
			int num;
			num = strong[i] + i;
			int j = i + 1;
			while (check[j] != true)
			{
				if (num > strong[i + 1])
					j++;
			}
			if (num > strong[i + 1] && check[i + 1] == true)
			{
				check[i] = true;
				res.push_back(i + 1);
			}
			
		}
		
		
	}
	sort(res.begin(), res.end());

	if (res.size() == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
	}
	
	return 0;
	// 1 1 2 2 3 , 3 3 4 4 5 8 , 1 1 2 4 4 5 << ¹Ý·Ê
}