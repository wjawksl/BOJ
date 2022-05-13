#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char a[60], b[60];
	string A, B, sliced_B;
	scanf("%s %s", a, b);
	A = a;
	B = b;
	int mini = 0, cnt, len = B.length() - A.length() + 1;

	for (int i = 0; i < len; i++)
	{
		cnt = 0;
		sliced_B = B.substr(i, A.length());
		for (int j = 0; j < A.length(); j++)
		{
			if (A[j] != sliced_B[j]) cnt++;
		}
		if (i == 0) mini = cnt;
		else mini = min(mini, cnt);
	}
	printf("%d", mini);
	return 0;
}