#include<iostream>
#include<vector>
#include<string>
#include<map>

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
string name, query;
map <int, string> poke1;
map <string, int> poke2;
int main()
{
	FIO;
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> name;
		poke1.insert({ i, name });
		poke2.insert({ name, i });
	}
	for (int i = 0; i < M; i++)
	{
		cin >> query;
		int a = query[0] - '0';

		if (0 <= a && a <= 9) cout << poke1[stoi(query)] << "\n";
		else cout << poke2[query] << "\n";
		
	}
	
	return 0;
}