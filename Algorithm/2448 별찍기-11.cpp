#include<iostream>
#include<algorithm>

using namespace std;
char axis[3080][6165];
void draw_triangle(int x,int y)
{
	axis[x][y] = '*';
	axis[x + 1][y - 1] = '*';
	axis[x + 1][y + 1] = '*';

	for (int i = y - 2; i <= y + 2; i++)
		axis[x + 2][i] = '*';
}
void make_star(int a, int b,int n)
{
	int p1[2] = { a + n / 2,b - n / 2 };
	int p2[2] = { a + n / 2,b + n / 2 };

	if (n == 3)
		draw_triangle(a, b);
	else
	{
		make_star(a, b, n / 2);
		make_star(p1[0], p1[1], n / 2);
		make_star(p2[0], p2[1], n / 2);
	}
		
}
int main()
{
	fill(&axis[0][0], &axis[3072][6143], ' ');

	int num,range;

	scanf("%d", &num);
	make_star(0, num - 1,num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 2*num-1; j++)
			printf("%c", axis[i][j]);

		printf("\n");
	}

	return 0;
}