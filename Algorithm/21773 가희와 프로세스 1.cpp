#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Process{
	int A;
	int B;
	int C;
};
struct comp {
	bool operator()(Process p1, Process p2) {
		if (p1.C < p2.C) return true;
		else if (p1.C == p2.C)
		{
			if (p1.A > p2.A) return true;
			else return false;
		}
		else return false;
	}
};
priority_queue<Process, vector<Process>, comp> pq;
int main()
{
	int T, n, A, B, C;
	cin >> T >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A >> B >> C;
		pq.push({ A,B,C });
	}
	for (int i = 0; i < T; i++)
	{
		if (pq.empty()) break;

		Process p = pq.top();
		pq.pop();

		cout << p.A << "\n";

		p.B--;
		p.C--;

		if (p.B > 0) pq.push(p);
	}

	return 0;
}