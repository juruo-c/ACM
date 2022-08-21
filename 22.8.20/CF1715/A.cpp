#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 1 && m == 1)
        {
            puts("0");
            continue;
        }
        int ans = n + m - 2;
        ans *= 2;
        ans -= max(n - 1, m - 1);
        ans ++;
        printf("%d\n", ans);
    }
    return 0;
}
