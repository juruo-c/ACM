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

const int N = 1000005, mod = 1000000007;

int n;
char s[N];
int nt[N];
int num[N];
int f[20][N];

void getnext()
{
    int i = 0, j = -1;
    nt[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i ++, j ++ ;
            nt[i] = j;
            num[i] = num[nt[i]] + 1;
        }
        else j = nt[j];
    }
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
        scanf("%s", s);
        n = strlen(s);
        for (int i = 1; i <= n; i ++ ) num[i] = 0;
        getnext();
        // for (int i = 1; i <= n; i ++ )
        //     printf("nt[%d] = %d\n", i, nt[i]);
        // for (int i = 1; i <= n; i ++ ) num[i] += num[nt[i]];

        for (int i = 1; i <= n; i ++ ) f[0][i] = nt[i];
        for (int j = 1; j < 20; j ++ )
            for (int i = 1; i <= n; i ++ )
                f[j][i] = f[j - 1][f[j - 1][i]];

        int ans = 1;
        for (int i = 1; i <= n; i ++ )
        {
            int t = i;
            for (int j = 19; j >= 0; j -- )
                if (f[j][t] * 2 > i) t = f[j][t];
            ans = 1LL * ans * (num[nt[t]] + 1) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
