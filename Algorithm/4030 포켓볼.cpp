#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int T=1, a, b, cnt,tri;
	while(true)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;
		cnt = 0;

		for (int i = 2; i <= 44721; i++)
		{
			tri = i * (i + 1) / 2;
			if (tri <= a - 1)
				continue;
			if (tri >= b - 1)
				break;
			tri++;
			if (tri == (int)sqrt(tri) * (int)sqrt(tri))
				cnt++;
		}
		cout << "Case " << T << ": " << cnt << "\n";
		T++;
	}
	
	return 0;
}