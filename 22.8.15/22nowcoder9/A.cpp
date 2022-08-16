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

int a[N];
int cnt[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    LL ans = 0;
    int cur = 1;
    cnt[a[1]] = 1;
    for (int l = 1, r = 1; l <= n; l ++ )
    {
        while (r <= n && cur < m) 
        {
            r ++;
            if (!cnt[a[r]]) cur ++;
            cnt[a[r]] ++;
        }
        if (cur == m) ans += n - r + 1;
        cnt[a[l]] --;
        if (!cnt[a[l]]) cur --;
    }

    printf("%lld\n", ans);
    return 0;
}
