//https://www.acwing.com/problem/content/241/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10005;

int n, m;
struct Query
{
    int l, r, rela;
}q[N];
int a[N];
int fa[N], d[N];

int getf(int x)
{
    if (x == fa[x]) return x;
    int t = getf(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = t;
}

int main()
{
    scanf("%d%d", &n, &m);
    int t = 0;
    for (int i = 1; i <= m; i ++ )
    {
        char op[10];
        scanf("%d %d %s", &q[i].l, &q[i].r, op);
        if (op[0] == 'e') q[i].rela = 0;
        else q[i].rela = 1;
        a[++ t] = q[i].l - 1;
        a[++ t] = q[i].r;
    }
    sort(a + 1, a + 1 + t);
    n = unique(a + 1, a + 1 + t) - a - 1;

    for (int i = 1; i <= n; i ++ ) fa[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int x = lower_bound(a + 1, a + 1 + n, q[i].l - 1) - a;
        int y = lower_bound(a + 1, a + 1 + n, q[i].r) - a;
        int fx = getf(x), fy = getf(y);
        if (fx == fy)
        {
            if ((d[x] ^ d[y]) != q[i].rela)
                return printf("%d", i - 1), 0;
        }
        else
        {
            fa[fx] = fy;
            d[fx] = q[i].rela ^ d[x] ^ d[y];
        }
    }
    printf("%d", m);
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10005;

int n, m;
int a[N];
struct Query
{
    int l, r, rela;
}q[N];
int fa[N * 2];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
    scanf("%d%d", &n, &m);
    int t = 0;
    for (int i = 1; i <= m; i ++ )
    {
        char s[5];
        scanf("%d %d %s", &q[i].l, &q[i].r, s);
        q[i].rela = (s[0] == 'o');
        a[++ t] = q[i].l - 1;
        a[++ t] = q[i].r;
    }
    sort(a + 1, a + 1 + t);
    n = unique(a + 1, a + 1 + t) - a - 1;

    for (int i = 1; i <= 2 * n; i ++ ) fa[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int x = lower_bound(a + 1, a + 1 + n, q[i].l - 1) - a;
        int y = lower_bound(a + 1, a + 1 + n, q[i].r) - a;
        if (q[i].rela == 0)
        {
            if (getf(x) == getf(y + n))
                return printf("%d", i - 1), 0;
            fa[getf(x)] = getf(y);
            fa[getf(x + n)] = getf(y + n);
        }
        else
        {
            if (getf(x) == getf(y))
                return printf("%d", i - 1), 0;
            fa[getf(x + n)] = getf(y);
            fa[getf(x)] = getf(y + n);
        }
    }
    printf("%d", m);
    return 0;
}
