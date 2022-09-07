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

const int mod = 998244353;
const int N = 600005;

int n;
int p[N], q[N];
int a[N];
int f[N][2];

int dfs(int pos, int x, int y, int who)
{
    if (x > n && who == 0) return f[pos][who] = 0;
    if (y > n && who == 1) return f[pos][who] = 0;   
    if (f[pos][who] != -1) return f[pos][who];
    if (pos == 2 * n)
    {
        if (who == 0 && a[pos] == p[x])
            return f[pos][who] = 1;
        if (who == 1 && a[pos] == q[y])
            return f[pos][who] = 1;
        return f[pos][who] = 0;
    }
    f[pos][who] = 0;
    if (who == 0 && a[pos] == p[x]) f[pos][who] = (dfs(pos + 1, x + 1, y, who) + dfs(pos + 1, x + 1, y, who ^ 1)) % mod;
    if (who == 1 && a[pos] == q[y]) f[pos][who] = (dfs(pos + 1, x, y + 1, who) + dfs(pos + 1, x, y + 1, who ^ 1)) % mod;
    return f[pos][who];
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
        memset(f, -1, sizeof f);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &q[i]);
        for (int i = 1; i <= 2 * n; i ++ )
            scanf("%d", &a[i]);
        printf("%d\n", (dfs(1, 1, 1, 0) + dfs(1, 1, 1, 1)) % mod);
        // for (int i = 1; i <= 2 * n; i ++ )
        //     cout << f[i][0] << " " << f[i][1] << endl;
    }
    return 0;
}
