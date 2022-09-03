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

const int N = 100005, mod = 1000000007;

bool vis[N];
int p[N], miu[N];
LL c[N];

void init()
{
    miu[1] = 1;
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            miu[i] = -1;
        }
        for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = -miu[i];
        }
    }

    for (int i = 1; i <= p[0]; i ++ )
        for (int j = 1; j * p[i] < N; j ++ )
            c[j * p[i]] += miu[j];
    for (int i = 1; i < N; i ++ )
        c[i] += c[i - 1];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    init();
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n > m) swap(n, m);

        LL ans = 0;
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans += 1LL * (n / l) * (m / l) * (c[r] - c[l - 1]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}
