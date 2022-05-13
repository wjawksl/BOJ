#include<iostream>
#include<string>

using namespace std;
int main()
{
	int M,N;
	scanf("%d %d", &N, &M);

	string N_string = to_string(N), str;

	for (int i = 0; i < N * N_string.length(); i++)
	{
		if (str.length() == M) break;
		str += N_string[i % N_string.length()];
	}
	printf("%s", str.c_str());
	return 0;
}