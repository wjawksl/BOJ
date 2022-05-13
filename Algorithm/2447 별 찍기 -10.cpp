#include<iostream>
#include<algorithm>

using namespace std;

void make_star(int a, int b, int n)
{
	if ((a / n) % 3 == 1 && (b / n) % 3 == 1) printf(" ");
	else
	{
		if (n < 3) printf("*");
		else make_star(a, b, n / 3);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			make_star(i, j, num);
		}
		printf("\n");
	}
	return 0;
}