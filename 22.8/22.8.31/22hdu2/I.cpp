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

const int N = 2000005;

int P, Q, e;
int p[N];
bool vis[N];
int cnt;
LL factor[N];

void getprime(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i])
            p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && 1LL * i * p[j] <= n; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

void getfactor(LL n)
{
    for (int i = 1; i <= p[0]; i ++ )
        if (n % p[i] == 0)
        {
            factor[++ cnt] = p[i];
            while (n % p[i] == 0) n /= p[i];
        }
    if (n != 1) factor[++ cnt] = n;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    getprime(N - 5);
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%d", &P, &Q, &e);
        cnt = 0;
        getfactor(1LL * P * Q - 1);
        int res = 0;
        LL ans;
        for (int i = 1; i <= cnt; i ++ )
        {
            LL m = factor[i];
            LL r = 1LL * e * Q % m;
            if (m > P && m > Q && m > e && e == 1LL * r * P % m)
            {
                ans = m;
                res ++;
            }
        }
        if (!res || res > 1) puts("shuanQ");
        else printf("%lld\n", 1LL * e * Q % ans);
    }
    return 0;
}
