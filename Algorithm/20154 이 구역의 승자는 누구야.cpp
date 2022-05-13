#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector <int> alphabet;
vector <int> tmp;

int main()
{
	string str;
	int stroke[26] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

	cin >> str;
	for (int i = 0; i < str.size(); i++)
		alphabet.push_back(stroke[str[i] - 'A']);

	while (alphabet.size() != 1)
	{
		for (int i = 0; i < alphabet.size(); i +=2)
		{
			if (i == alphabet.size() - 1)
			{
				tmp.push_back(alphabet[i] % 10);
				break;
			}
			tmp.push_back((alphabet[i] + alphabet[i + 1]) % 10);
		}
		alphabet = tmp;
		tmp.clear();
	}
	if (alphabet[0] % 2 == 1)
		cout << "I'm a winner!";
	else
		cout << "You're the winner?";
	
	return 0;
}