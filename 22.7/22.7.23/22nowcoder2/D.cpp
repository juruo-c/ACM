#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int N = 2005;

int n, m;
struct edge
{
    int to, next;
    double w;
}e[N << 1];
int head[N], cnt;
int a[N], b[N], c[N], d[N];
int num[N];
double dis[N];
bool vis[N];

void add(int u, int v, double w)
{
    e[++ cnt] = edge{v, head[u], w};
    head[u] = cnt;
}

bool spfa()
{
    for (int i = 1; i <= n; i ++ )
        num[i] = 0, dis[i] = 0;
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
        q.push(i), vis[i] = true;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                num[v] = num[u] + 1;
                if (num[v] >= n)
                    return false;
                if (!vis[v])
                {
                    vis[v];
                    q.push(v);
                }
            }
        }
    }
    return true;
}

bool check(double w)
{
    for (int i = 1; i <= m; i ++ )
        e[i].w = -log2(w * c[i] / a[i]);

    return spfa();
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++ )
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]), add(b[i], d[i], 0);
        
        double l = 0, r = 1;
        while (r - l > 1e-10)
        {
            double mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }

        printf("%.10f\n", l);

    }
    return 0;
}