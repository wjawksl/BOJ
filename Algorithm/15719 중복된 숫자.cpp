#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp;
	//scanf("%d", &N);
	cin >> N;
	bool* arr = (bool*)malloc(sizeof(bool) * N);


	for (int i = 0; i < N; i++)
	{
		//scanf("%d", &tmp);
		cin >> tmp;
		if (arr[tmp - 1] == true)
		{
			//printf("%d", tmp);
			cout << tmp;
			break;
		}
		else
		{
			arr[tmp - 1] = true;
		}
	}
	free(arr);
	return 0;
}