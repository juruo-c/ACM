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

int p[N], miu[N];
bool vis[N];

void getmiu()
{
    miu[1] = 1;
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i])
        {
            miu[i] = -1;
            p[++ p[0]] = i;
        }
        for (int j = 1; j <= p[0] && i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
            miu[i * p[j]] = - miu[i];
        }
    }
    for (int i = 1; i < N; i ++ )
        miu[i] += miu[i - 1];
}

bool check(LL x, int k)
{
    LL ans = 0;
    for (LL l = 1, r; l <= sqrt(x); l = r + 1)
    {
        r = sqrt(x / (x / (l * l)));
        ans += x / (l * l) * (miu[r] - miu[l - 1]);
    }
    return ans >= k;
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
        int k;
        scanf("%d", &k);
        LL l = 1, r = 2e9;
        while (l < r)
        {
            LL mid = (l + r) >> 1;
            if (check(mid, k)) r = mid;
            else l = mid + 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}
