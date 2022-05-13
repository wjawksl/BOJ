#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, a;
vector<int> answer;
vector<int> myAnswer;

int main()
{
	cin >> N >> M;
	answer.resize(N + 2);
	myAnswer.resize(N + 2);

	for (int i = 1; i < N + 1; i++)
	{
		cin >> answer[i];
	}
	for (int i = 1; i < M + 1; i++)
	{
		cin >> a;
		myAnswer[a] = answer[a];
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (myAnswer[i] == 0)
		{
			for(int j = 1; j <= 5; j++)
			{
				if (myAnswer[i - 1] != j && myAnswer[i + 1] != j && answer[i] != j)
				{
					myAnswer[i] = j;
					break;
				}
			}
		}		
	}
	for (int i = 1; i < N + 1; i++)
	{
		cout << myAnswer[i] << " ";
	}
	return 0;
}