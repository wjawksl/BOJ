#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
string str;

int N, c, a;
int main()
{
	cin >> N;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'C') c++;
		else a++;
	}

	int n_int = c / (a + 1);
	float n_float = c / ((a + 1)*1.0f);
	
	if (n_float > n_int) cout << n_int + 1;
	else cout << n_int;
	return 0;
}