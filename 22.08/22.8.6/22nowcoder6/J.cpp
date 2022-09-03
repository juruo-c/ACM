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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        LL a, b, c, x;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &x);
        if (a - 2 * b == 0)
        {
            if (x - c == 0 || x + c - b == 0)
            {
                puts("Yes");
            }
            else puts("No");
            continue;
        }
        if ((x - c) % (a - 2 * b) == 0)
        {
            puts("Yes");
            continue;
        }
        if ((x + c - b) % (a - 2 * b) == 0)
        {
            puts("Yes");
            continue;
        }
        puts("No");
    }
    return 0;
}
