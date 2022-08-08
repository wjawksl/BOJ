#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
vector<string> v;
int main()
{
	int R, C, Rg, Cg, Rp, Cp, cnt = 0;
	string str;
	cin >> R >> C >> Rg >> Cg >> Rp >> Cp;

	for (int i = 0; i < R; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == 'P') cnt++;
		}
	}
	if (cnt == Rp * Cp) cout << 0;
	else cout << 1;

	return 0;
}