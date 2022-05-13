#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	deque <int> deq;
	int T, N, cnt;
	string p, arr,str;
	bool flag,dir;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cnt = 0;
		dir = true;
		flag = true;
		cin >> p;
		cin >> N;
		cin >> arr;
		
		while (cnt < N)
		{
			str = "";
			for (int i = 1; i < arr.size(); i++)
			{
				if (0 <= arr[i] - '0' && arr[i] - '0' <= 9)
					str += arr[i];
				else
				{
					if (i != 1)
					{
						deq.push_back(stoi(str));
						str = "";
						cnt++;
					}
				}
			}
		}
		/*for (int i = 1; i < 2 * N; i += 2)
			deq.push_back(arr[i] - '0');*/

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (dir)
					dir = false;
				else
					dir = true;
			}
			else if (p[i] == 'D')
			{
				if (deq.empty())
				{
					flag = false;
					break;
				}
				if(dir)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}
		if (flag == false)
			cout << "error" << "\n";
		else if (deq.empty())
			cout << "[]" << "\n";
		else
		{
			int tmp;
			cout << "[";
			if (dir)
			{
				while (true)
				{
					tmp = deq.front();
					deq.pop_front();

					if (deq.empty())
					{
						cout << tmp << "]\n";
						break;
					}
					else
						cout << tmp << ",";
				}
			}
			else
			{
				while (true)
				{
					tmp = deq.back();
					deq.pop_back();

					if (deq.empty())
					{
						cout << tmp << "]\n";
						break;
					}
					else
						cout << tmp << ",";
				}
			}
		}
	}
	return 0;
}