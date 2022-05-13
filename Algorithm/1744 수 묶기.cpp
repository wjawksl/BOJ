#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;
vector<int> m;
int N;
int zero = 0;
int one = 0;

int main()
{   
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num == 1) one++;
        else if (num > 0) p.push_back(num);
        else if (num < 0) m.push_back(num);
        else zero++;
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end());

    if (p.size() % 2 == 1) p.push_back(1);
    if (m.size() % 2 == 1) m.push_back(zero > 0 ? 0 : 1);

    int ans = 0;
    for (int i = 0; i < p.size(); i += 2) {
        ans += p[i] * p[i + 1];
    }
    for (int i = 0; i < m.size(); i += 2) {
        ans += m[i] * m[i + 1];
    }
    ans = ans + one;
    cout << ans;
    return 0;
}
