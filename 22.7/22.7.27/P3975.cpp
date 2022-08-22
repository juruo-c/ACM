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

const int N = 500005, mod = 1000000007;

int t, k;
struct edge
{
    int to, next;
}e[N << 1];
int head[N << 1], cnt;
char s[N];
int siz[N << 1];
LL f[N << 1];
bool vis[N << 1];

struct SAM
{
    int ch[N << 1][26], len[N << 1], fa[N << 1];
    int last, tot;

    void sam_init()
    {
        last = tot = 1;
        memset(ch, 0, sizeof ch);
        memset(len, 0, sizeof len);
        memset(fa, 0, sizeof fa);
    }

    void add(int c)
    {
        int p = last;
        int np = last = ++ tot;
        len[np] = len[p] + 1;
        siz[tot] = 1;
        for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (len[q] == len[p] + 1) fa[np] = q;
            else
            {
                int nq = ++ tot;
                memcpy(ch[nq], ch[q], sizeof ch[q]);
                fa[nq] = fa[q];
                fa[q] = fa[np] = nq;
                len[nq] = len[p] + 1;
                for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
    }
}sam;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v);
        siz[u] += siz[v];
    }
    f[u] = siz[u];
}

int dfs_(int u)
{
    if (vis[u]) return f[u];
    vis[u] = true;
    for (int i = 0; i < 26; i ++ )
    {
        int v = sam.ch[u][i];
        if (v)
            f[u] += dfs_(v);
    }
    return f[u];
}

void solve(int u, int k)
{
    if (k == siz[u]) return;
    k -= siz[u];
    for (int i = 0; i < 26; i ++ )
    {
        int t = sam.ch[u][i];
        if (t)
        {
            if (f[t] >= k) 
            {
                putchar('a' + i);
                solve(t, k);
                return;
            }
            else k -= f[t];
        }
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int T = 1;
    while (T --)
    {
        scanf("%s", s + 1);
        scanf("%d%d", &t, &k);
        int n = strlen(s + 1);

        sam.sam_init();
        for (int i = 1; i <= n; i ++ )
            sam.add(s[i] - 'a');
        
        if (!t)
        {
            for (int i = 2; i <= sam.tot; i ++ )
                f[i] = siz[i] = 1;
        }
        else 
        {
            for (int i = 2; i <= sam.tot; i ++ )
                add(sam.fa[i], i);
            dfs(1);
        }

        f[1] = siz[1] = 0;
        dfs_(1);

        // cout << "siz: " << endl;
        // for (int i = 1; i <= sam.tot; i ++ )
        //     cout << i << " " << siz[i] << endl;

        // cout << sam.tot << endl;
        // for (int i = 1; i <= sam.tot; i ++ )
        //     cout << i << " " << f[i] << endl;
        
        if (k > f[1])
        {
            puts("-1");
            continue;
        }

        solve(1, k);

    }
    return 0;
}
