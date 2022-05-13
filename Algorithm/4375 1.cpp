#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;
int n, a;

int main() {

    while (scanf("%d", &n) !=  EOF) {

        for (int i = 1; i <= n; i++) {

            a = a * 10 + 1;
            a %= n;

            if (a == 0) {

                printf("%d\n", i); //È½¼öÃâ·Â
                break;
            }
        }
    }

}
