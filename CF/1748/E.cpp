#include <bits/stdc++.h>
#define ZYCMH

using namespace std;

const int N = 200005, mod = 1000000007;

struct Node
{
    int p, mx;
};
struct Tree
{
    int l, r;
}t[N];
int idx;

int n, m;
Node st[N][20];
int lg[N];
unordered_map<int, int> f[N];

int get(int l, int r)
{
    int k = lg[r - l + 1];
    return (st[l][k].mx < st[r - (1 << k) + 1][k].mx) ? st[r - (1 << k) + 1][k].p : st[l][k].p;
}

void build(int& u, int l, int r)
{
    if (l > r) return;
    if (!u) u = ++ idx;
    if (l == r) return;
    int p = get(l, r);
    build(t[u].l, l, p - 1);
    build(t[u].r, p + 1, r);
}

void dfs(int u)
{
    if (!u) return;
    dfs(t[u].l);
    dfs(t[u].r);
    for (int i = 1; i <= m; i ++ )
    {
        f[u][i] = 1LL * f[t[u].l][i - 1] * f[t[u].r][i] % mod;
        f[u][i] = (f[u][i] + f[u][i - 1]) % mod;
    }
}

int main()
{

    // #ifdef ZYCMH
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // #endif 

    for (int i = 2; i < N; i ++ )
        lg[i] = lg[i / 2] + 1;

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        idx = 0;
        for (int i = 1; i < N; i ++ )
            t[i].l = t[i].r = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &st[i][0].mx), st[i][0].p = i;
        
        for (int i = 1; i < 20; i ++ )
            for (int j = 1; j + (1 << i) - 1 <= n; j ++ )
                if (st[j][i - 1].mx < st[j + (1 << (i - 1))][i - 1].mx)
                    st[j][i] = st[j + (1 << (i - 1))][i - 1];
                else
                    st[j][i] = st[j][i - 1];

        int rt = 0;
        build(rt, 1, n);

        for (int i = 0; i <= m; i ++ )
            f[0][i] = 1;

        dfs(rt);

        printf("%d\n", f[rt][m]);
    }

    return 0;
}