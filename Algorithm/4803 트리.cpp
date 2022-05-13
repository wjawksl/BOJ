#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>

#define SIZE 505 

using namespace std;

typedef pair<int, int> pii;
int parent[SIZE];
int ranks[SIZE];
int check[SIZE];
int n, m, n1, n2;


int find(int node)
{
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find(parent[node]);
}
void UnionByRank(int n1, int n2)
{
    n1 = find(n1);
    n2 = find(n2);

    if (n1 != n2)
    {
        if (ranks[n1] < ranks[n2]) swap(n1, n2);
        if (check[n2] == -1) check[n1] = -1;
        parent[n2] = n1;
        if (ranks[n1] == ranks[n2]) ranks[n1]++;
    }
    else check[n1] = -1;
}

int main()
{
    int testcase = 0;
    while (1) {
        testcase++;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = i;
            ranks[i] = 1;
            check[i] = 0;
        }
        for (int i = 1; i < m + 1; i++)
        {
            cin >> n1 >> n2;
            UnionByRank(n1, n2);
        }

        map<int, int> m;
        for (int i = 1; i < n + 1; i++)
        {
            int f = find(i);
            if (check[f] == -1) continue;
            m.insert({ f, 0 });
        }
        int cnt = m.size();

        if (cnt == 0) {
            cout << "Case " << testcase << ": No trees." << "\n";
        }
        else if (cnt == 1) {
            cout << "Case " << testcase << ": There is one tree." << "\n";
        }
        else {
            cout << "Case " << testcase << ": A forest of " << cnt << " trees." << "\n";
        }
    }

    return 0;
}
