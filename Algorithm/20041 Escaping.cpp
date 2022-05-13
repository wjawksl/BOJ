#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#define FIO ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef pair<int, int> pii;

int N, xPos, yPos;
vector <pii> police;
bool route[4] = {true,true,true,true };
bool flag = false;
int main()
{
	FIO;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> xPos >> yPos;
		police.push_back(make_pair(xPos, yPos));
	}
	cin >> xPos >> yPos;
	for (int i = 0; i < N; i++)
	{
		int pX = police[i].first, pY = police[i].second;
		int xLen = abs(pX - xPos), yLen = abs(pY - yPos);
		if ((pX >= xPos) && (pY > yPos))
		{
			if (yLen <= xLen)
				route[0] = false;
			if (xLen <= yLen)
				route[1] = false;
		}
		else if ((pX < xPos) && (pY >= yPos))
		{
			if (yLen <= xLen)
				route[2] = false;
			if (xLen <= yLen)
				route[1] = false;
		}
		else if ((pX <= xPos) && (pY < yPos))
		{
			if (yLen <= xLen)
				route[2] = false;
			if (xLen <= yLen)
				route[3] = false;
		}
		else if ((pX > xPos) && (pY <= yPos))
		{
			if (yLen <= xLen)
				route[0] = false;
			if (xLen <= yLen)
				route[3] = false;
		}
		for (int j = 0; j < 4; j++)
		{
			if (route[j] == true)
				break;
			if (j == 3)
				flag = true;
		}
		if (flag)
			break;
	}
	if (flag)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}