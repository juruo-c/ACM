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

const int N = 1000005;

int n;
int a[N];
int v[N];
int ans[N];

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
            scanf("%d", &a[i]), v[i] = 0;
        
        v[0] = n + 1;
        for (int i = 1; i <= n; i ++ )
        {
            int l = 0, r = n;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (v[mid] > a[i])
                    l = mid;
                else r = mid - 1;
            }
            ans[i] = l + 1;
            v[l + 1] = max(v[l + 1], a[i]);
        }

        int res = 0;
        for (int i = 1; i <= n; i ++ )
            res = max(res, ans[i]);
        printf("%d\n", res);
        for (int i = 1; i <= n; i ++ )
        {
            if (i > 1) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
