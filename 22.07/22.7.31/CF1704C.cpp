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

const int N = 100005, mod = 1000000007;

int n, m;
int a[N];
int b[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++ )
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + m);

        for (int i = 1; i < m; i ++ )
            b[i] = a[i + 1] - a[i] - 1;
        
        b[m] = a[1] - 1 + n - a[m];

        sort(b + 1, b + 1 + m);

        // for (int i = 1; i <= m; i ++ )
        //     printf("%d: %d\n", i, b[i]);

        int ans = 0;
        int t = 0;
        for (int i = m; i >= 1; i -- )
            if (b[i] - t > 0)
            {
                int tt = b[i] - t;
                if (tt > 1) tt --;
                ans += tt;

                t += 4;
            }
            else break;

        printf("%d\n", n - ans);
    }
    return 0;
}
