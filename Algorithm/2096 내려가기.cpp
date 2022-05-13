#include<iostream>
#include<algorithm>

using namespace std;

int arr[100005][3];
int l, m, r;
int prv_max[3];
int cur_max[3];
int prv_min[3];
int cur_min[3];
int N;

int main()
{
	cin >> N;
	cin >> l >> m >> r;
	cur_max[0] = l; cur_max[1] = m; cur_max[2] = r;
	cur_min[0] = l; cur_min[1] = m; cur_min[2] = r;
	for (int i = 1; i < N; i++)
	{
		cin >> l >> m >> r;
		prv_max[0] = cur_max[0]; prv_max[1] = cur_max[1]; prv_max[2] = cur_max[2];
		cur_max[0] = l + max(prv_max[0], prv_max[1]);
		cur_max[1] = m + max(prv_max[0], max(prv_max[1], prv_max[2]));
		cur_max[2] = r + max(prv_max[1], prv_max[2]);

		prv_min[0] = cur_min[0]; prv_min[1] = cur_min[1]; prv_min[2] = cur_min[2];
		cur_min[0] = l + min(prv_min[0], prv_min[1]);
		cur_min[1] = m + min(prv_min[0], min(prv_min[1], prv_min[2]));
		cur_min[2] = r + min(prv_min[1], prv_min[2]);
	}
	cout << max(cur_max[0], max(cur_max[1], cur_max[2])) << " " << min(cur_min[0], min(cur_min[1], cur_min[2]));
	
	return 0;
}