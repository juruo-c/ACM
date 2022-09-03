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

const int N = 200005;

int n, m;
struct edge
{
    int from, to, next, w;
}e[N << 1];
int head[N], cnt;
int a[N];
bool b[N];

void add(int u, int v, int w)
{
    e[++ cnt] = {u, v, head[u], w};
    head[u] = cnt;
}

void solve(int bit)
{
    memset(b, true, sizeof b);

    for (int i = 1; i <= 2 * m; i += 2 )
        if (!(e[i].w >> bit & 1))
            // printf("%d\n", !(e[i].w >> bit & 1));
            b[e[i].from] = b[e[i].to] = false;

    for (int i = 1; i <= n; i ++ )
    {
        if (!b[i]) continue;

        bool flag = true;
        for (int j = head[i]; j; j = e[j].next)
        {
            int v = e[j].to, w = e[j].w;
            if (w >> bit & 1)
            {
                if (v == i) 
                {
                    flag = false;
                    break;
                }
                flag &= b[v];
            }
        }

        if (flag) b[i] = false;
    }

    for (int i = 1; i <= n; i ++ ) 
        if (b[i])
            a[i] += 1 << bit;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    for (int i = 29; i >= 0; i -- )
        solve(i);

    for (int i = 1; i <= n; i ++ )
        printf("%d ", a[i]);

    return 0;
}
