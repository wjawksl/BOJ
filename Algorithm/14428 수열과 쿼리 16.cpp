#include<iostream>
#include<algorithm>
#include<vector>

#define FIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9 + 1

using namespace std;

typedef long long ll;

int arr[100005];
vector<ll> IDT;
ll B = 1;

void Update(ll node)
{
	ll idx = node + B;	
	while (idx > 1)
	{
		idx /= 2;
		if (arr[IDT[idx * 2]] == arr[IDT[idx * 2 + 1]])
		{
			IDT[idx] = min(IDT[idx * 2], IDT[idx * 2 + 1]);
		}
		else if (arr[IDT[idx * 2]] > arr[IDT[idx * 2 + 1]])
		{
			IDT[idx] = IDT[idx * 2 + 1];
		}
		else if (arr[IDT[idx * 2]] < arr[IDT[idx * 2 + 1]])
		{
			IDT[idx] = IDT[idx * 2];
		}
	}
}
ll IDTMin(ll L, ll R)
{
	ll resIdx = 0;
	L += B; R += B;
	while (L <= R)
	{
		if (L % 2 == 1)
		{
			if (arr[resIdx] >= arr[IDT[L]])
			{
				if (arr[resIdx] == arr[IDT[L]])
				{
					resIdx = min(resIdx, IDT[L]);
				}
				else resIdx = IDT[L];
			}
		}
		if (R % 2 == 0)
		{
			if (arr[resIdx] == arr[IDT[R]])
			{
				resIdx = min(resIdx, IDT[R]);
			}
			else if (arr[resIdx] > arr[IDT[R]])
			{
				resIdx = IDT[R];
			}
		}
		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}
	return resIdx;
}
int main()
{
	FIO;
	ll N, M, a, b, c;
	cin >> N;
	IDT.resize(4 * N);
	arr[0] = INF;
	while (B < N) B *= 2;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i + 1];
		IDT[i + B] = i + 1;
		Update(i);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			arr[b] = c;
			Update(b - 1);
		}
		else cout << IDTMin(b - 1, c - 1) << "\n";
	}
	return 0;
}