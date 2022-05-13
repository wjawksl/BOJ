#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int N, M;
	char s[25];
	string str;
	vector <string> v1;
	vector <string> v2;
	vector <string> res;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		getchar();
		str = s;
		v1.push_back(str);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", s);
		getchar();
		str = s;
		v2.push_back(str);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	res.resize(v1.size() + v2.size());
	auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
	res.erase(iter, res.end());

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
	{
		printf("%s\n", res[i].c_str());
	}
	cout << endl;
	return 0;
}