#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
vector <vector<int>> video;

void get_cnt(int r, int c, int size)
{
	int color = video[r][c];
	
	for (int i = r; i < r + size; i++)
	{
		for (int j = c; j < c + size; j++)
		{
			if (video[i][j] != color)
			{
				cout << "("; // ����� �Ѵ�
				get_cnt(r, c, size / 2); // �� 1��и�
				get_cnt(r, c + (size / 2), size / 2); // �� 2��и�
				get_cnt(r + (size / 2), c, size / 2); // �� 3��и�
				get_cnt(r + (size / 2), c + (size / 2), size / 2); // �� 4��и�
				cout << ")"; // ����� ����
				return;
			}
		}
	}
	if (color == 1)
		cout << 1;
	else
		cout << 0;
}
int main()
{
	int N;
	string str;
	vector <int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			v.push_back(str[j] - '0');
		}
		video.push_back(v);
		v.clear();
	}
	get_cnt(0, 0, N);
	return 0;
}