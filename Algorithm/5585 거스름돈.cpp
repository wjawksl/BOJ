#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int pay, cnt = 0;
	cin >> pay;
	int change = 1000 - pay;
	while (change >= 500)
	{
		change -= 500;
		cnt++;
	}
	while (change >= 100)
	{
		change -= 100;
		cnt++;
	}
	while (change >= 50)
	{
		change -= 50;
		cnt++;
	}
	while (change >= 10)
	{
		change -= 10;
		cnt++;
	}
	while (change >= 5)
	{
		change -= 5;
		cnt++;
	}
	cnt += change;
	cout << cnt;
	return 0;
}