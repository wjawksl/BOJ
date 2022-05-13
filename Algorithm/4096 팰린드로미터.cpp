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
	int n, cnt, len,tmp_len;
	char s[100];
	string str,tmp;
	while (true)
	{
		scanf("%s", s);
		str = s;
		len = str.length();

		if (str.length() == 1 && str[0] == '0') break;
		cnt = 0;
		while (!is_palindrom(str, 0, str.length()-1))
		{
			n = stoi(str);
			cnt++;
			n ++;
			tmp = to_string(n);
			tmp_len = tmp.length();
			if (tmp_len < len)
				for (int i = 0; i < len - tmp_len; i++)
					tmp = "0" + tmp;

			str = tmp;
			
		}
		printf("%d\n", cnt);
	}
	return 0;
}