#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int K, L;
string stNum;
map <int, string> list;
map <string, int> overlap;
vector <string> sequence;

int main()
{
	cin >> K >> L;
	for (int i = 1; i < L + 1; i++)
	{
		cin >> stNum;
		sequence.push_back(stNum);
	}

	for (int i = L - 1; i >= 0; i--)
	{
		int size = overlap.size();
		overlap.insert({ sequence[i], L - 1 - i });
		if(size != overlap.size())
			list.insert({ i, sequence[i] });
	}
	int i = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		cout << it->second << "\n";
		i++;
		if (i == K)
			break;
	}
	return 0;
}