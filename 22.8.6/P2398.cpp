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

LL phi[N], p[N];
bool vis[N];

void getphi(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= p[0] && i * p[j] <= n; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for (int i = 1; i <= n; i ++ )
        phi[i] += phi[i - 1];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    getphi(n);
    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += (phi[r] - phi[l - 1]) * (n / l) * (n / l);
    }
    printf("%lld\n", ans);
    return 0;
}
