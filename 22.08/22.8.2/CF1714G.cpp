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

const int N = 200005, mod = 1000000007;

int n;
struct edge
{
    int to, next, a, b;
}e[N];
int head[N], cnt;
int dep[N];
LL A[N], B[N];
LL List[N];
int ans[N];

void add(int u, int v, int a, int b)
{
    e[++ cnt] = {v, head[u], a, b};
    head[u] = cnt;
}

void dfs(int u)
{
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        A[v] = A[u] + e[i].a;
        B[v] = B[u] + e[i].b;
        dep[v] = dep[u] + 1;
        List[dep[v]] = B[v];
        ans[v] = upper_bound(List + 1, List + dep[v] + 1, A[v]) - List - 1;
        // cout << "v = " << v << " List: " << endl;
        // for (int i = 1; i <= dep[v]; i ++ )
        //     cout << "List[" << i << "] = " << List[i] << endl;
        dfs(v);
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            head[i] = dep[i] = 0, A[i] = B[i] = 0;
        for (int i = 2; i <= n; i ++ )
        {
            int p, a, b;
            scanf("%d%d%d", &p, &a, &b);
            add(p, i, a, b);
        }   
        dfs(1);

        // for (int i = 2; i <= n; i ++ )
        // {
        //     cout << "i = " << i << endl;
        //     for (int j = 0; j < List[i].size(); j ++ )
        //         cout << List[i][j] << " ";
        //     cout << endl;
        // }

        for (int i = 2; i <= n; i ++ )
        {
            if (i > 2) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");

    }
    return 0;
}
