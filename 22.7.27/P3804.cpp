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

const int N = 2000005, mod = 1000000007;

int n;
char s[N];
struct edge
{
    int to, next;
}e[N];
int head[N], cnt;
int siz[N];

struct SAM
{
    int ch[N][26], len[N], fa[N];
    int last, tot; //上个节点，节点个数
    
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
                len[nq] = len[p] + 1;
                fa[q] = fa[np] = nq;
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
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);

        sam.sam_init();
        for (int i = 1; i <= n; i ++ )
            sam.add(s[i] - 'a');
        
        for (int i = 2; i <= sam.tot; i ++ )
            add(sam.fa[i], i);
        
        dfs(1);

        LL ans = 0;
        for (int i = 2; i <= sam.tot; i ++ )
            if (siz[i] > 1)
                ans = max(ans, 1LL * siz[i] * sam.len[i]);
        
        printf("%lld\n", ans);

    }
    return 0;
}
