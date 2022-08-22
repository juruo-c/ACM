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
LL b[N];

bool check(int x)
{
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
        b[i] = a[i] + 1LL * i * x;

    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= x; i ++ ) ans += b[i];

    return ans <= m;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
