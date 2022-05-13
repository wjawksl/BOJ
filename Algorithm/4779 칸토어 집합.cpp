#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int white, blue;
char arr[532000];

void Cantor(int L, int R, int size)
{
	if (size == 1) return; // 탈출 조건
	int newR = L + size / 3, newL = R - size / 3; // 새로운 구간 정의

	for (int i = newR; i <= newL; i++) // 구간 값 갱신
	{
		arr[i] = ' ';
	}
	Cantor(L, newR - 1, size / 3);
	Cantor(newL + 1, R, size / 3);
}
int main()
{
	FIO;
	int N, num;

	while (cin >> N)
	{
		int L = 1, R = (int)pow(3, N);
		fill(arr, arr + 532000, 0);
		fill(arr + 1, arr + R + 1, '-');
		Cantor(L, R, R);

		for (int i = L; i <= R; i++)
			cout << arr[i];
		cout << "\n";
	}

	return 0;
}