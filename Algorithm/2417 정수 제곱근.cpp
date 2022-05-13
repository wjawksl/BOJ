#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long int n, tmp;
	cin >> n;

	tmp = (long long int)sqrt(n);
	if (pow(tmp, 2) == n)
		printf("%lld", tmp);
	else
		printf("%lld", tmp + 1);


	return 0;
}