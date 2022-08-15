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

int n, k;
int a[N], b[N];

bool check(int x)
{
    int t = k;
    for (int i = 1; i <= n; i ++ ) b[i] = a[i];
    for (int i = 1; i <= n; i ++ )
        if (2 * b[i] < x)
        {
            if (!t) return false;
            t --;
            b[i] = 1e9;
        }    
    
    if (t >= 2) return true;
    else if(t == 0)
    {
        int mx = 0;
        for (int i = 1; i < n; i ++ )
            mx = max(min(b[i], b[i + 1]), mx);
        return mx >= x;
    }

    int mx = 0;
    for (int i = 1; i <= n; i ++ )
        mx = max(mx, b[i]);
    return mx >= x;
}

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
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        
        int l = 1, r = 1e9;
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
