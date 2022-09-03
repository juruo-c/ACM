#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n;
int a[N];
int cnt[20];
LL x[N];

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d", &n);

        LL sum = 0;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &a[i]);
            for (int j = 0; j < 15; j ++ )
                if (a[i] & (1 << j)) cnt[j] ++;
            sum += a[i];
        }

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 0; j < 15; j ++ )
                if (cnt[j] >= i) x[i] += (1 << j);
            x[i] *= n;
        }

        LL up = 0;
        for (int i = 1; i <= n; i ++ )
            up += (x[i] - sum) * (x[i] - sum);

        LL down = 1LL * n * n * n;

        if (up == 0)
        {
            printf("0/1\n");
            continue;
        }

        LL g = gcd(up, down);
        printf("%lld/%lld\n", up / g, down / g);

    }
    return 0;
}
