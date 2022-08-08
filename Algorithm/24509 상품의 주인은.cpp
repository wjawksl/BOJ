#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> korean;
vector<pii> english;
vector<pii> math;
vector<pii> science;

int check[200005];
int N;

bool comp(pii n1, pii n2)
{
	if (n1.first == n2.first)
	{
		return n1.second < n2.second;
	}
	else
	{
		return n1.first > n2.first;
	}
}
int main()
{
	cin >> N;
	int n, a, b, c, d;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> n >> a >> b >> c >> d;

		korean.push_back({ a,n });
		english.push_back({ b,n });
		math.push_back({ c,n });
		science.push_back({ d,n });
	}

	sort(korean.begin(), korean.end(), comp);
	sort(english.begin(), english.end(), comp);
	sort(math.begin(), math.end(), comp);
	sort(science.begin(), science.end(), comp);

	for (int i = 0; i < N; i++)
	{
		if (!check[korean[i].second])
		{
			cout << korean[i].second << " ";
			check[korean[i].second] = true;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!check[english[i].second])
		{
			cout << english[i].second << " ";
			check[english[i].second] = true;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!check[math[i].second])
		{
			cout << math[i].second << " ";
			check[math[i].second] = true;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!check[science[i].second])
		{
			cout << science[i].second;
			check[science[i].second] = true;
			break;
		}
	}
	return 0;
}