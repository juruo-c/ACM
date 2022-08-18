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

const int N = 3005, mod = 1000000007;

int ans[N];
int a[N][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, p;
    cin >> n >> p;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n % p; i ++ )
        ans[i] = a[i][i];
    
    for (int i = 1; i <= n; i ++ )
    {
        if (i > 1) printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}