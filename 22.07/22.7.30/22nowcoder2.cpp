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

const int N = 10005, mod = 1000000007;

int n, k, d;
int X[N][55], Y[N][55];
double c[N][55], a[55][55];
double Ynew[N][55];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d%d%d", &n, &k, &d);
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= k; j ++ )
                scanf("%d", &X[i][j]);
        
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= d; j ++ )
                scanf("%d", &Y[i][j]);
        
        for (int i = 1; i <= n; i ++ )
        {
            double mo = 0;
            for (int j = 1; j <= k; j ++ )
                mo += X[i][j] * X[i][j];
            mo = sqrt(mo);
            for (int j = 1; j <= k; j ++ )
                c[i][j] = X[i][j] / mo;
        }

        for (int p = 1; p <= k; p ++ )
            for (int o = 1; o <= d; o ++ )
                for (int j = 1; j <= n; j ++ )
                    a[p][o] += c[j][p] * Y[j][o];

        for (int i = 1; i <= n; i ++ )
            for (int o = 1; o <= d; o ++ )
                for (int p = 1; p <= k; p ++ )
                    Ynew[i][o] += c[i][p] * a[p][o];

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= d; j ++ )
            {
                if (j > 1) printf(" ");
                printf("%.10f", Ynew[i][j]);
            }
            puts("");
        }

    }
    return 0;
}
