#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string S, T;
bool flag = false;
string Recursion(string str)
{
	if (str.size() == S.size() || flag) // S�� ���̰� �������ų� �̹� �� ���ڿ��� ���� �� �ִٸ�
	{
		if (str == S)
			flag = true;
		return str;
	}
	if (str.size() > 0)
	{
		if (str[0] == 'A') // ù ��° ���ڰ� A�� ���
		{
			if (str.back() == 'A')
			{
				str.pop_back();
				Recursion(str);
				str.push_back('A');
			}
		}
		else // ù ��° ���ڰ� B�� ���
		{
			string tmp = str; // B�� �߰� �ƴٰ� �������� �� (������ ���ڰ� A�̵� B�̵� �������)
			reverse(tmp.begin(), tmp.end());
			str = tmp;

			str.pop_back();
			Recursion(str);

			reverse(tmp.begin(), tmp.end());
			str = tmp;
			if (str.back() == 'A') // ������ ���ڰ� A�� ��� >> A�� �߰� �ƴٰ� �������� �� << ù ��° ����
			{
				str.pop_back();
				Recursion(str);
				str.push_back('A');
			}
		}
	}
	return str;
}
int main()
{
	cin >> S >> T;
	Recursion(T);
	cout << flag;
	return 0;
}