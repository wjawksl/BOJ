#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int _max = 0, N, K, tmp;
vector <int> v;

void get_max(int res, int a, int b)
{
	res += a * pow(10, b); // 1 >> 11 >> 111 >> 1111 >> 5111 >> 7111 >> 511 
	if (res > N) return; // 탈출 조건!!

	_max = max(_max, res); // 값 갱신
	for (int i = 0; i < K; i++)
	{
		get_max(res, v[i], b + 1); // 재귀 호출
	}
}

int main()
{
	int num;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < K; i++)
		get_max(0, v[i], 0);

	printf("%d", _max);

	return 0;
}