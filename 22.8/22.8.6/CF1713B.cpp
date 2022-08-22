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

const int N = 100005, mod = 1000000007;

int a[N];
int mx1[N], mx2[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]), mx1[i] = mx2[i] = a[i];

        for (int i = 2; i <= n; i ++ )
            mx1[i] = max(mx1[i], mx1[i - 1]);
        
        for (int i = n - 1; i >= 1; i -- )
            mx2[i] = max(mx2[i], mx2[i + 1]);

        bool flag = true;
        for (int i = 2; i < n; i ++ )
            if (mx1[i] > a[i] && a[i] < mx2[i])
            {
                flag = false;
                break;
            }

        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
