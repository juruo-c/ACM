//http://oj.daimayuan.top/course/10/problem/469
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 500005;

int n, m;
int a[N];
map<int, int> last;
int l[N], r[N];
int cnt;

int f[N][30];
int lg[N];

int ask(int l, int r)
{
    int k = lg[r - l + 1];
    return  min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        if (last[a[i]])
        {
            int t = last[a[i]];
            if (t > l[cnt])
            {
                l[++ cnt] = t;
                r[cnt] = i;
            }
        }
        last[a[i]] = i;
    }

    for (int i = 2; i <= cnt; i ++ )
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= cnt; i ++ )
        f[i][0] = r[i] - l[i];
    for (int j = 1; (1 << j) <= cnt; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= cnt; i ++ )
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    for (int i = 1; i <= m; i ++ )
    {
        int ql, qr;
        scanf("%d%d", &ql, &qr);
        ql = lower_bound(l + 1, l + 1 + cnt, ql) - l;
        qr = upper_bound(r + 1, r + 1 + cnt, qr) - r - 1;
        if (ql > qr) puts("-1");
        else printf("%d\n", ask(ql, qr));
    }

    return 0;
}
