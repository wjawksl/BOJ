#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int get_gcd(long long a, long long b)
{
	if (a % b == 0)
		return b;
	return get_gcd(b, a % b);
}

int main()
{
	long long a, b, gcd, lcm;
	scanf("%lld %lld", &a, &b);
	if (a > b)
		swap(a, b);
	gcd = get_gcd(a, b);
	lcm = (a / gcd) * b;
	printf("%lld\n",lcm);
	
	return 0;
}