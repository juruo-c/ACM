#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005, mod = 1000000007, INF = 0x3f3f3f3f;

int n, x;
struct Seq
{
    int l, r;
    bool operator < (const Seq& b) const
    {
        if (l == b.l) return r > b.r;
        return l < b.l;
    }
}s[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i ++ )
        {
            int a;
            scanf("%d", &a);
            s[i].l = a - x;
            s[i].r = a + x;
        }

        int ans = 0, l = s[1].l, r = s[1].r;
        for (int i = 2; i <= n; i ++ )
        {  
            if (s[i].r < l || s[i].l > r)
            {
                ans ++;
                l = s[i].l, r = s[i].r;
            }
            else
            {
                l = max(l, s[i].l);
                r = min(r, s[i].r);
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}
