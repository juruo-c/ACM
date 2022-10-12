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

int n;
int f[N];
vector<int> a[N];
int b[N];

int dfs(int u)
{
    if (u == n + 1) return 1;
    if (f[u] != -1) return f[u];
    f[u] = 0;
    if (b[u] <= n - u) f[u] |= dfs(u + b[u] + 1);
    int sz = a[u].size();
    for (int i = 0; i < sz; i ++ )
        f[u] |= dfs(a[u][i] + 1);
    return f[u];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            f[i] = -1, a[i].clear();

        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &b[i]);
            if (i - b[i] >= 1) a[i - b[i]].push_back(i);
        }

        printf("%s\n", dfs(1) ? "YES" : "NO");

    }
    return 0;
}
