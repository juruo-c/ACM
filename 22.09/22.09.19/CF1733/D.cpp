#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3005;
char s[N], t[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s%s", s + 1, t + 1);

        bool flag = false;
        int cnt = 0, last = -1;
        for (int i = 1; i <= n; i ++ )
        {
            if (s[i] != t[i])
            {
                cnt ++;
                if (last == i - 1)
                    flag = true;
                last = i;
            }
        }

        if (cnt % 2)
        {
            puts("-1");
            continue;
        }

        if (n == 2 && cnt == 2)
        {
            printf("%d\n", x);
            continue;
        }
        if (cnt == 2 && flag)
        {
            printf("%d\n", min(x, 2 * y));
            continue;
        }

        printf("%lld\n", 1LL * cnt / 2 * y);   
    }
    return 0;
}
