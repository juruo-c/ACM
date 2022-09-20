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
        if (x && y) 
        {
            puts("-1");
            continue;
        }
        if (x == 0 && y == 0)
        {
            puts("-1");
            continue;
        }
        if (x < y) swap(x, y);
        n --;
        if (n % x)
        {
            puts("-1");
            continue;
        }
        for (int i = 1, j = 1; i <= n; i ++ )
        {
            printf("%d ", j);
            if (i % x == 0) j = i + 2;
        }
        puts("");
    }
    return 0;
}
