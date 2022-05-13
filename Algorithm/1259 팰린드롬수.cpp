#include<iostream>
#include<string>

using namespace std;

bool is_palindrom(string str, int idx1, int idx2)
{
	if (idx1 > idx2)
		return true;
	if (str[idx1] != str[idx2])
		return false;
	return is_palindrom(str, ++idx1, --idx2);
}

int main()
{
	char s[10];
	string str;
	while (true)
	{
		scanf("%s", s);
		if (s[0] == '0')
			break;
		str = s;
		if (is_palindrom(str, 0, str.length() - 1))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
