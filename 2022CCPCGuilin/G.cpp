#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int a[N];
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
LL f[N], g[N];
int fa[N];
int st, ed;
LL curlen; 
bool is[N];
LL ans1, ans2;
int point[N];
int p_cnt;
LL premx[N], sufmx[N], pre[N], suf[N];
LL mx[N][6];
LL h[N];
void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dp(int u, int ff)
{
    if (is[u]) return;
    f[u] = a[u], g[u] = a[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dp(v, u);
        g[u] = max(g[u], f[u] + f[v]);
        f[u] = max(f[u], f[v] + a[u]);
    }
}

void dfs1(int u, int ff, LL len, int& ed)
{
    if (len > curlen)
    {
        curlen = len;
        ed = u;
    }
    fa[u] = ff;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs1(v, u, len + a[v], ed);
    }
}
bool cmp(LL a, LL b)
{
    return a > b;
}

void dfs2(int u, int ff)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs2(v, u);
        LL t = mx[v][0] + a[v];
        mx[u][4] = t;
        sort(mx[u], mx[u] + 5, cmp);
    }
}

void dfs3(int u, int ff)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;

        LL t = (mx[v][0] + a[v] == mx[u][0]) ? mx[u][1] : mx[u][0]; 
        h[v] = max(h[u], t) + a[u];   
    
        dfs3(v, u);
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    if (n == 1)
    {
        puts("0");
        return 0;
    }

    st = 1;
    dfs1(1, 0, a[1], ed);
    dfs1(ed, 0, a[ed], st);
    int p = st;
    while (p)
        is[p] = true, p = fa[p];
    for (int i = 1; i <= n; i ++ )
        if (is[i])
        {
            for (int j = head[i]; j; j = e[j].next)
            {
                int v = e[j].to;
                if (!is[v])
                    dp(v, i);
            }
        }
    LL smallMx = 0;
    for (int i = 1; i <= n; i ++ )
        if (!is[i])
            smallMx = max(smallMx, g[i]);
    ans1 = smallMx + curlen;
    p = st;
    while (p)
    {
        point[++ p_cnt] = p;
        p = fa[p];
    }
    LL sum = 0;
    for (int i = 1; i <= p_cnt; i ++ )
    {
        int u = point[i];
        sum += a[u];
        for (int j = head[u]; j; j = e[j].next)
        {
            int v = e[j].to;
            if (!is[v])
                pre[i] = max(pre[i], f[v]);
        }
        pre[i] += sum;
    }
    sum = 0;
    for (int i = p_cnt; i >= 1; i -- )
    {
        int u = point[i];
        sum += a[u];
        for (int j = head[u]; j; j = e[j].next)
        {
            int v = e[j].to;
            if (!is[v])
                suf[i] = max(suf[i], f[v]);
        }
        suf[i] += sum;
    }
    for (int i = 1; i <= p_cnt; i ++ )
        premx[i] = max(pre[i], premx[i - 1]);
    for (int i = p_cnt; i >= 1; i -- )
        sufmx[i] = max(suf[i], sufmx[i + 1]);
    for (int i = 1; i < p_cnt; i ++ )
        ans1 = max(ans1, premx[i] + sufmx[i + 1]);

    // 1.2 ans2 !!
    dfs2(1, 0);
    // for (int i = 1; i <= n; i ++ )
    // {
    //     cout << "i = " << i << endl;
    //     for (int j = 0; j < 5; j ++ )
    //         cout << mx[i][j] << " ";
    //     cout << endl;
    // }
    dfs3(1, 0);
    LL ans2 = 0;
    for (int i = 1; i <= n; i ++ )
    {
        mx[i][4] = h[i];
        sort(mx[i], mx[i] + 5, cmp);
        LL t = 0;
        for (int j = 0; j < 4; j ++ )
            t += mx[i][j];
        // cout << "i = " << i << endl;
        // for (int j = 0; j < 5; j ++ )
        //     cout << mx[i][j] << " ";
        // cout << endl;
        ans2 = max(ans2, t);
    }

    // cout << ans1 << " " << ans2 << endl;

    printf("%lld\n", max(ans1, ans2));

    return 0;
}