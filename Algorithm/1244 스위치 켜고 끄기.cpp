#include<iostream>
#include<stdlib.h>
#include<algorithm>

int main(void)
{
	int N_sw, N_st, tmp_s, tmp_num,idx1,idx2;
	scanf("%d", &N_sw);

	int sw[101];


	for (int i = 1; i < N_sw + 1; i++)
	{
		scanf("%d", &sw[i]);
	}
	scanf("%d", &N_st);
	for (int i = 1; i < N_st + 1; i++)
	{
		scanf("%d %d", &tmp_s, &tmp_num);
		if (tmp_s == 1)
		{
			for (int j = tmp_num; j < N_sw + 1; j += tmp_num)
			{
				if (sw[j])
				{
					sw[j] = 0;
				}
				else
				{
					sw[j] = 1;
				}
			}
		}
		else
		{
			idx1 = tmp_num;
			idx2 = tmp_num;
			while (idx1>=1 && idx2<=N_sw)
			{
				if (sw[idx1] != sw[idx2])
				{
					break;
				}
				idx1--;
				idx2++;
			}
			idx1++;
			idx2--;
			for (int k = idx1; k < idx2 + 1; k ++)
			{
				if (sw[k])
				{
					sw[k] = 0;
				}
				else
				{
					sw[k] = 1;
				}
			}
		}
	}
	for (int i = 1; i < N_sw + 1; i++)
	{
		printf("%d ", sw[i]);
		if (i % 20 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}