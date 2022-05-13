#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector <int> A;
	
	vector <int> accsum;
	int n, q, num, a, b, sum = 0;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		A.push_back(num);
	}
	
	sort(A.begin(), A.end());
	accsum.push_back(0);
	for (int i = 0; i < n; i++)
	{
		sum += A[i];
		accsum.push_back(sum);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", accsum[b] - accsum[a - 1]);
	}


	return 0;
}