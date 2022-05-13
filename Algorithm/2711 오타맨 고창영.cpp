#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	char tmp[85];
	int test_case, w;
	
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %s", &w, tmp);
		string  str = tmp;
		printf("%s\n", (str.substr(0,w-1) + str.substr(w)).c_str());
	}
	
	
	return 0;
}