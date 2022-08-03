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

const int N = 200005, M = 200005, mod = 1000000007;

int n, m;
vector<int> g[N];
int head[N], cnt;
int dfn[N], low[N], dfn_cnt;
int stack[N], top;
bool cut[N];
vector<int> dcc[N];
int dcc_cnt;
int id[N];
int d[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++ dfn_cnt;
    stack[++ top] = u;
    if (u == 1 && g[u].size() == 0)
    {
        dcc[++ dcc_cnt].push_back(u);
        return;
    }
    int flag = 0;
    for (int i = 0; i < g[u].size(); i ++ )
    {
        int v = g[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                flag ++;
                if (u != 1 || flag > 1) cut[u] = true;
                dcc_cnt ++;
                int z;
                do
                {
                    z = stack[top --];
                    dcc[dcc_cnt].push_back(z);
                    id[z] = dcc_cnt;
                } while (z != v);
                id[u] = dcc_cnt;
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
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
        int u, v;scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tarjan(1);

    bool flag = false;
    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
        {
            flag = true;
            break;
        }

    int L = 0, R = 0;
    if (!flag)
    {
        int t = dcc_cnt;
        for (int i = 1; i <= n; i ++ )
            if (cut[i]) id[i] = ++ t;
        for (int i = 1; i <= dcc_cnt; i ++ )
            for (int j = 0; j < dcc[i].size(); j ++ )
            {
                int v = dcc[i][j];
                if (cut[v])
                {
                    d[i] ++;
                    d[id[v]] ++;
                }
            }
        
        for (int i = 1; i <= t; i ++ )
            if (d[i] >= 3)
            {
                flag = true;
                break;
            }

        if (!flag)
        {
            for (int i = 1; i <= t; i ++ )
                if (d[i] == 1)
                {
                    if (!L) L = i;
                    else R = i;
                }
        }

    }

    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);

        if (flag)
        {
            puts("NO");
            continue;
        }

        if (cut[x] || cut[y])
        {
            puts("NO");
            continue;    
        }
        
        if (dcc_cnt == 1)
        {
            puts("YES");
            continue;
        }
        
        y = id[y], x = id[x];
        if (x > y) swap(x, y);

        if (x == L && y == R) puts("YES");
        else puts("NO");

    }

    return 0;
}
