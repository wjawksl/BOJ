#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int val = 0;

void get_cnt(int r, int c, int size)
{
	int add = int(pow(size / 2, 2));

	if (size == 1)
	{
		printf("%d", val);
		return;
	}

	if (r < size / 2 && c < size / 2)
		get_cnt(r, c, size / 2);
	else if (r < size / 2 && c >= size / 2)
	{
		val += add;
		get_cnt(r, c - (size / 2), size / 2);
	}
	else if (r >= size / 2 && c < size / 2)
	{
		val += add * 2;
		get_cnt(r - (size / 2), c, size / 2);
		
	}
	else
	{
		val += add * 3;
		get_cnt(r - (size / 2), c - (size / 2), size / 2);
	}
}
int main()
{
	int N, res;
	int r, c;
	scanf("%d %d %d", &N, &r, &c);
	get_cnt(r, c, int(pow(2, N)));
	
	return 0;
}