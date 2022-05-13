#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int GCD(int n1, int n2)
{
	int tmp;
	while (n2 != 0)
	{
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	return n1;
}

int main()
{
	int n1, n2, gcd,j;
	vector<int> v;
	scanf("%d %d", &n1, &n2);
	gcd = GCD(n1, n2);
	for (int i = 1; i <= sqrt(gcd); i++)
	{
		if (gcd % i == 0)
		{
			printf("%d %d %d\n", i, n1 / i, n2 / i);
			j = gcd / i;
			if (i != j) printf("%d %d %d\n", j, n1 / j, n2 / j);
		}
	}
	return 0;
}