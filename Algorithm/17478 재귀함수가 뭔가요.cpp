#include<iostream>
#include<algorithm>

using namespace std;

int cnt = 0;
void print_(int a)
{
	for (int i = 0; i < 4 * a; i++)
	{
		printf("_");
	}
}

void what_is_recur(int n)
{
	print_(cnt); printf("\"����Լ��� ������?\"\n");
	if (n == 0)
	{
		print_(cnt);
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		print_(cnt); printf("��� �亯�Ͽ���.\n");
		return;
	}
	else
	{
		print_(cnt); printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		print_(cnt); printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		print_(cnt); printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		cnt++;
		what_is_recur(n - 1);
		cnt--;
		print_(cnt); printf("��� �亯�Ͽ���.\n");
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	what_is_recur(N);
	return 0;
}