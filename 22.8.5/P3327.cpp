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

const int N = 50005, mod = 1000000007;

int p[N], miu[N];
bool vis[N];
int miuS[N];
LL f[N];

LL F(int n)
{
    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += 1LL * (n / l) * (r - l + 1);
    }
    return ans;
}

void getmiu()
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
    for (int i = 1; i < N; i ++ )
        miuS[i] = miuS[i - 1] + miu[i];
    for (int i = 0; i < N; i ++ )
        f[i] = F(i);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    getmiu();
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n > m) swap(n, m);
        LL ans = 0;
        for (int l = 1, r; l <= n; l = r + 1 )
        {
            r = min(n / (n / l), m / (m / l));
            ans += 1LL * (miuS[r] - miuS[l - 1]) * f[n / l] * f[m / l];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
