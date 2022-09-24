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

const int N = 200005;

int n, k;
int a[N];
LL sum[N];

bool solve()
{
    int l = k - 1, r = k + 1;
    LL mx = a[k];
    int l_mx_pos = k, r_mx_pos = k;
    while(l >= 1 && r <= n)
    {
        // cout << "l = " << l << " r = " << r << endl;
        LL x = mx + sum[l_mx_pos - 1] - sum[l];
        while (l >= 1 && x + a[l] >= 0)
        {
            x += a[l];
            if (mx < x)
                mx = x, l_mx_pos = l;
            l --;
        }
        // cout << "l = " << l << endl;
        if (!l) return true;
        LL tt = mx;
        x = mx + sum[r - 1] - sum[r_mx_pos];
        while (r <= n && x + a[r] >= 0)
        {
            x += a[r];
            if (mx < x)
                mx = x, r_mx_pos = r;
            r ++;
        }
        // cout << "r = " << r << endl;
        if (r == n + 1) return true;
        if (mx == tt) return false;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);

        if (k == 1 || k == n) 
        {
            puts("YES");
            continue;
        }

        for (int i = 1; i <= n; i ++ )
            sum[i] = sum[i - 1] + a[i];

        if (solve())
        {
            puts("YES");
            continue;
        }
        reverse(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i ++ )
            sum[i] = sum[i - 1] + a[i];
        k = n - k + 1;
        if (solve())
        {
            puts("YES");
            continue;
        }
        puts("NO");

    }
    return 0;
}
