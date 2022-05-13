#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>

#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

priority_queue <int, vector<int>> pqMax;
priority_queue <int, vector<int>, greater<int>> pqMin;

int main()
{
	FIO;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (pqMax.size() == pqMin.size())
		{
			pqMax.push(num);
			if (!pqMin.empty() && pqMax.top() > pqMin.top())
			{
				int num1 = pqMax.top(); pqMax.pop();
				int num2 = pqMin.top(); pqMin.pop();

				pqMin.push(num1); pqMax.push(num2);
			}
			cout << pqMax.top() << "\n";
		}
		else
		{
			pqMin.push(num);
			if (!pqMin.empty() && pqMax.top() > pqMin.top())
			{
				int num1 = pqMax.top(); pqMax.pop();
				int num2 = pqMin.top(); pqMin.pop();

				pqMin.push(num1); pqMax.push(num2);
			}
			cout << pqMax.top() << "\n";				
		}
	}
	return 0;
}