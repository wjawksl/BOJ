#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int visited[11];
vector<char> v;
vector<char> ch;
string str;
int N, M, cnt;
bool flag;
void Print()
{
	if (v.size() == str.size())
	{
		cnt++;
		if (cnt == N)
		{
			cout << str << " " << N << " = ";
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
			cout << "\n";
			flag = true;
		}		
		return;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(ch[i]);
			Print();
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int main()
{	
	while (cin >> str)
	{
		cin >> N;
		flag = false;
		cnt = 0;
		v.resize(0); ch.resize(0);
		fill(visited, visited + 11, 0);

		for (int i = 0; i < str.size(); i++)
		{
			ch.push_back(str[i]);
		}
		Print();
		if (!flag) cout << str << " " << N << " = " << "No permutation" << "\n";		
	}	
	return 0;
}