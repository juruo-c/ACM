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

const int mod = 1000000007;

int n, m;
int a[10][10];
int id[10][10];

int res[] = 
{15,
339,
4761,
52929,
517761,
4767849,
339,
16485,
518265,
14321907,
387406809,
460338013,
4761,
518265,
43022385,
486780060,
429534507,
792294829,
52929,
14321907,
486780060,
288599194,
130653412,
748778899,
517761,
387406809,
429534507,
130653412,
246336683,
579440654,
4767849,
460338013,
792294829,
748778899,
579440654,
236701429};

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &m);
        if (n == 1 || m == 1) puts("0");
        else if (n >= 8 || m >= 8) 
            printf("%d\n", qpow(3, n * m));
        else{
            for (int i = 2, k = 0; i <= 7; i ++ )
                for (int j = 2; j <= 7; j ++, k ++ )
                    if (i == n && j == m)
                    {
                        printf("%d\n", res[k]);
                        break;
                    }
        }   
    }
    return 0;
}
