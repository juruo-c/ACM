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
int c[N];

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
        for (int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i ++ )
        {
            c[i] = (a[i] - a[(i - 1 + n) % n] + 3) % 3;
            if (c[i] == 1) c1 ++;
            else if(c[i] == 2) c2 ++;
        }

        if (c1 < c2) puts("No");
        else 
        {
            if ((c1 - c2) % 3 == 0) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
