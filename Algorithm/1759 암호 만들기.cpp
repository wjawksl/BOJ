#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> cipher;
vector<char> v;
bool visited[30];
int L, C, vowel = 0, cons = 0; // 모음, 자음 개수를 세는 변수를 선언

bool isVowel(int i) // 모음인지?
{
	if (cipher[i] == 'a' || cipher[i] == 'e' || cipher[i] == 'i' || cipher[i] == 'o' || cipher[i] == 'u')
		return true;
	else return false;
}
void go()
{
	if (v.size() == L)
	{
		if (vowel >= 1 && cons >= 2)
		{
			for (int i = 0; i < L; i++)
			{
				cout << v[i];
			}
			cout << "\n";
		}
		return; // 탈출!
	}
	for (int i = 0; i < C; i++)
	{
		if (!v.empty() && v.back() > cipher[i]) continue; // 조합 처리
		int idx = cipher[i] - 'a'; // 문자를 인덱스로 변환(아스키 코드)
		if (!visited[idx])
		{
			v.push_back(cipher[i]);
			visited[idx] = true;

			if (isVowel(i)) vowel++;
			else cons++;

			go();

			if (isVowel(i)) vowel--;
			else cons--;

			v.pop_back();
			visited[idx] = false;
		}
	}
}
int main()
{
	char c;
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> c;
		cipher.push_back(c);
	}
	sort(cipher.begin(), cipher.end());
	go();

	return 0;
}