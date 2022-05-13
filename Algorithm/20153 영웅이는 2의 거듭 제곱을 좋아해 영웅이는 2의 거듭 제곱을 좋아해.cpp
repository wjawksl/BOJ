#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<cmath>
#include<vector>
using namespace std;

vector <int> index(22);
vector <int> tmpv(22);
vector <int> v;
vector <string> vs(2222223);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int powArr[23];
	int N, num, tmp = 0, res = 0;
	
	for (int i = 0; i < 23; i++)
		powArr[i] = pow(2, i);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		vs[i] = bitset<22>(v[i]).to_string();
		for (int j = vs[i].size() - 1; j >= 0; j--)
			index[vs[i].size() - 1 - j] += vs[i][j] - '0';
	}
	for (int i = 0; i < 22; i++)
	{
		if (index[i] % 2 == 1)
			tmp += powArr[i];
	}
	res = max(res, tmp);
	
	for (int i = 0; i < N; i++)
	{
		tmp = 0;
		tmpv = index;
		
		for (int j = vs[i].size() - 1; j >= 0; j--)
			tmpv[vs[i].size() - 1 - j] -= vs[i][j] - '0';
		for (int i = 0; i < 22; i++)
		{
			if (tmpv[i] % 2 == 1)
				tmp += powArr[i];
		}
		res = max(res, tmp);
	}
	
	cout << res << res;
	return 0;
}