#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>

using namespace std;

int main()
{
	int T, N, tmpX, tmpY, len, num,res;
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		deque <int> dq;
		int X = 0, Y = 0, cnt = 0;
		cin >> N >> len;
		for (int i = len-1; i >= 0; i--)
		{
			cin >> tmpX;
			X += tmpX * pow(10, i);
		}
		for (int i = len - 1; i >= 0; i--)
		{
			cin >> tmpY;
			Y += tmpY * pow(10, i);
		}
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			dq.push_back(num);
		}
		for (int i = 0; i < N; i++)
		{
			res = 0;
			for (int j = len - 1; j >= 0; j--)
			{
				res += dq[len - j - 1] * pow(10, j);
			}
			if (X <= res && res <= Y)
				cnt++;
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << cnt << "\n";
	}
	return 0;
}