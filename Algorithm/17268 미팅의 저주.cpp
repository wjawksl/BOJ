#include<iostream>
#include<algorithm>

#define NUM 987654321
using namespace std;
long long F[10005];

void Factorial()
{
	for (int i = 2; i < 10001; i++)
	{
		F[i] = (F[i - 1] * i) % NUM;
	}
}
int main()
{
	F[0] = 1; F[1] = 1;
	Factorial();

	return 0;
}