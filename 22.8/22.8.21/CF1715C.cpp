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

const int N = 100005;

int n, m;
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    LL ans = 0;
    for (int i = 1; i < n; i ++ )
        ans += 1LL * (a[i] != a[i + 1]) * i * (n - i);
    
    for (int i = 1; i <= m; i ++ )
    {
        int j, x;
        scanf("%d%d", &j, &x);

        ans -= 1LL * (a[j] != a[j - 1]) * (j - 1) * (n - j + 1);
        ans -= 1LL * (a[j] != a[j + 1]) * j * (n - j);

        a[j] = x;

        ans += 1LL * (a[j] != a[j - 1]) * (j - 1) * (n - j + 1);
        ans += 1LL * (a[j] != a[j + 1]) * j * (n - j);

        printf("%lld\n", ans + 1LL * n * (n + 1) / 2);
    }

    return 0;
}
