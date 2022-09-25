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

const int N = 105;

int a[N];
int b[N];
LL c[N];
LL f[N][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    LL ans = 0;
    for (int i = 2; i <= n; i ++ )
        ans += 1LL * (a[i] - a[i - 1]) * (a[i] - a[i - 1]), b[i - 1] = a[i] - a[i - 1];
    
    for (int i = 2; i < n; i ++ )
        c[i - 1] = 1LL * b[i] * b[i + 1];

    for (int i = 1; i < n - 1; i ++ )
        for (int j = 1; j < n - 1; j ++ )
            

    for (int j = 1; j <= n; j ++ )
    {
        
        printf("%lld\n", ans);
    }   

    return 0;
}
