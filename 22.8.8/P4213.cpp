#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1664510, mod = 1000000007;

int p[N + 10];
LL phi[N + 10], miu[N + 10];
bool vis[N + 10];
unordered_map<LL, LL> sum_miu;
unordered_map<LL, LL> sum_phi;

void pre()
{
    phi[1] = miu[1] = 1;
    for (int i = 2; i <= N; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            phi[i] = i - 1;
            miu[i] = -1;
        }
        for (int j = 1; j <= p[0] && i * p[j] <= N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j];
                miu[i  * p[j]] = 0;
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            miu[i * p[j]] = - miu[i];
        }
    }

    for (int i = 1; i <= N; i ++ )
        phi[i] += phi[i - 1];
    for (int i = 1; i <= N; i ++ )
        miu[i] += miu[i - 1];

}

inline int g_sum(int n)
{
    return n;
}

LL get_sum_miu(int n)
{   
    if (n <= N) return miu[n];
    if (sum_miu[n]) return sum_miu[n];
    LL ans = 1;
    for (int l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans -= 1LL * (g_sum(r) - g_sum(l - 1)) * get_sum_miu(n / l);
    }
    return sum_miu[n] = ans / g_sum(1);
}

LL get_sum_phi(int n)
{
    if (n <= N) return phi[n];
    if (sum_phi[n]) return sum_phi[n];
    LL ans = 1LL * n * (n + 1) / 2;
    for (int l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans -= 1LL * (g_sum(r) - g_sum(l - 1)) * get_sum_phi(n / l);
    }
    return sum_phi[n] = ans / g_sum(1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    pre();
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        printf("%lld %lld\n", get_sum_phi(n), get_sum_miu(n));
    }
    return 0;
}
