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

const int N = 200005, mod = 1000000007;

int n, m, k;
int a[N], b[N], c[N << 1];
int cnt;   
int up[N << 1], down[N << 1];
int suf[N << 1];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d%d", &a[i], &b[i]);
            c[++ cnt] = a[i];
            c[++ cnt] = b[i];
        }
        sort(c + 1, c + 1 + cnt);
        cnt = unique(c + 1, c + 1 + cnt) - c - 1;

        for (int i = 1; i <= n; i ++ )
        {
            int l = lower_bound(c + 1, c + 1 + cnt, a[i]) - c;
            int r = lower_bound(c + 1, c + 1 + cnt, b[i]) - c;
            // cout << "l = " << l << " r = " << r << endl;
            if (l < r) up[l] ++, up[r] --;
            else down[l] --, down[r] ++;
        }

        for (int i = 1; i < cnt; i ++ )
        {
            up[i] += up[i - 1], down[i] += down[i - 1];
            int c1 = (up[i] + m - 1) / m;
            int c2 = (down[i] + m - 1) / m;
            suf[i] = max(c1, c2);
        }

        // cout << "up = " << endl;
        // for (int i = 1; i <= cnt; i ++ )
        //     cout << up[i]<< " ";
        // cout << endl;

        // cout << "down = " << endl;
        // for (int i = 1; i <= cnt; i ++ )
        //     cout << down[i]<< " ";
        // cout << endl;

        LL ans = 0;
        for (int i = cnt - 1; i >= 1; i -- )
        {
            suf[i] = max(suf[i + 1], suf[i]);
            ans += 1LL * suf[i] * (c[i + 1] - c[i]);
        }
        if (c[1] != 1) ans += 1LL * suf[1] * (c[1] - 1);
        printf("%lld\n", ans * 2);

    }
    return 0;
}
