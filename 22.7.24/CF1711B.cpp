#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n, m;
int a[N];
int d[N];
PII e[N];

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        memset(d, 0, sizeof d);

        scanf("%d%d", &n, &m);
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]), ans += a[i];
        
        for (int i = 1; i <= m; i ++ )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u] ++, d[v] ++;
            e[i] = {u, v};
        }

        if (m % 2 == 0)
        {
            puts("0");
            continue;
        }
        
        int mi = 1000000;
        for (int i = 1; i <= n; i ++ )
            if (d[i] % 2) mi = min(mi, a[i]);
        
        for (int i = 1; i <= m; i ++ )
        {
            PII t = e[i];
            if (d[t.first] % 2 == 0 && d[t.second] % 2 == 0)
                mi = min(mi, a[t.first] + a[t.second]);
        }

        printf("%d\n", mi);

    }
    return 0;
}
