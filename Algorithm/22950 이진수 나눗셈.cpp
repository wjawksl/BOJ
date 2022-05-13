#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<int> v;
string str;
int N, K, idx;
bool flag = false;
int main()
{
	cin >> N >> str >> K;
	
	for (int i = N - 1; i >= 0; i--)
	{
		if (str[i] == '1')
		{
			flag = true;
			idx = (N - 1) - i;
			break;
		}
	}
	if (flag)
	{
		if (idx < K ) cout << "NO";
		else cout << "YES";
	}
	else
	{
		cout << "YES";
	}		
	return 0;
}