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
int b[N][N];
int pow10[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= min(n, 100); i ++ )
            for (int j = 1; j <= i; j ++ )
                scanf("%d", &b[i][j]);
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; i ++ )
        {
            int p;
            scanf("%d", &p);
            if (n <= 100)
            {
                int ans = 0;
                for (int i = 1; i <= n; i ++ )
                    ans = (10 * ans % p + b[n][i]) % p;
                printf("%d\n", ans);
            }
            else 
            {
                pow10[0] = 1;
                for (int i = 1; i < p - 1; i ++ )
                    pow10[i] = pow10[i - 1] * 10 % p;
                int ans = 0;
                for (int i = 1; i <= p - 1; i ++ )
                    ans = (ans + b[p - 1][i] * pow10[(n - i) % (p - 1)] % p) % p;
                printf("%d\n", ans);
            }
        }
        
    }
    return 0;
}
