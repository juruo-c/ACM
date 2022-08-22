#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n, k;
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        
        int ans = mod;
        for (int i = 1; i <= a[1]; i ++ )
        {
            int mx = 0;
            for (int j = 1; j <= n; j ++ )
            {
                int p = min(k, a[j] / i);
                mx = max(mx, a[j] / p);
            }
            ans = min(ans, mx - i);
        }

        printf("%d\n", ans);
    }
    return 0;
}
