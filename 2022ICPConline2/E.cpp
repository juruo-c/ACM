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

int a[] = {3, 5, 7, 11, 13, 17, 21, 23};

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 2)
    {
        LL ans = 0;
        ans += 5 * (n / 2);
        if (n % 2) ans += 2;
        printf("%lld\n", ans);
    }
    else 
    {
        if (k & 1)
        {
            LL ans = k;
            n --;
            ans += 5 * (n / 2);
            if (n % 2) ans += 2;
            printf("%lld\n", ans);
        }
        else 
        {
            LL ans = k;
            int i = 0;
            for (; i < 8; i ++ )
                if (k % a[i]) break;
            ans += a[i];
            n -= 2;
            ans += 5 * (n / 2);
            if (n % 2) ans += 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
