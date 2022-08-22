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

int miu[N], p[N];
bool vis[N];
int miuS[N];

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
            miu[i * p[j]] = - miu[i];
        }
    }
    for (int i = 1; i < N; i ++ )
        miuS[i] = miuS[i - 1] + miu[i];
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
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        if (a > b) swap(a, b);

        a /= d, b /= d;

        LL ans = 0;
        for (int l = 1, r; l <= a; l = r + 1)
        {
            r = min(a / (a / l), b / (b / l));
            ans += 1LL * (miuS[r] - miuS[l - 1]) * (b / l) * (a / l); 
        }

        printf("%lld\n", ans);

    }
    return 0;
}
