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
int f[N];

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
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), a[i] ^= a[i - 1];
        map<int, int> pos;
        pos[0] = 0;
        for (int i = 1; i <= n; i ++ )
        {
            f[i] = f[i - 1] + 1;
            if (pos.find(a[i]) != pos.end())
            {
                int t = pos[a[i]];
                f[i] = min(f[i], f[t] + i - t - 1);
            }
            pos[a[i]] = i;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
