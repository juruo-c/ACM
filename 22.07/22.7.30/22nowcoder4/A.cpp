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

const int N = 100005, mod = 1000000007;

int n, m;
struct node
{
    int w;
    double p;
    bool operator < (const node& b) const{
        return w - b.w - w * b.p + b.w * p >= 0;
    }
}a[N];
double f[N][30];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i].w);
        for (int i = 1; i <= n; i ++ )
        {
            int q;
            scanf("%d", &q);
            a[i].p = 1.0 * q / 10000;
        }
        sort(a + 1, a + 1 + n);


        for (int i = n; i >= 1; i -- )
            for (int j = 1; j <= m; j ++ )
                f[i][j] = max(f[i + 1][j], f[i + 1][j - 1] * a[i].p + a[i].w);

        printf("%.10f\n", f[1][m]);

    }
    return 0;
}
