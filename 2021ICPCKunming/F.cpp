#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

double b[N];
vector<int> g[N];

double calc(double t)
{
    return t * t / 4;
}

bool cmp(int x, int y)
{
    return b[x] > b[y];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%lf", &b[i]);
    for (int i = 1; i < n; i ++ )   
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    double ans = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < g[i].size(); j ++ )
            ans = max(ans, calc((b[i] + b[g[i][j]]) / 2));
    
    for (int i = 1; i <= n; i ++ )
        sort(g[i].begin(), g[i].end(), cmp);
    
    for (int i = 1; i <= n; i ++ )
    {
        if (g[i].size() < 2) continue;
        int sz = g[i].size();
        ans = max(ans, calc((b[i] + b[g[i][0]] + b[g[i][1]]) / 3));
        ans = max(ans, calc((b[i] + b[g[i][sz - 1]] + b[g[i][sz - 2]]) / 3));
    }

    printf("%.10f\n", ans);

    return 0;
}
