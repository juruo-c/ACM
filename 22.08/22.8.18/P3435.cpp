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

const int N = 1000005;

int n;
char s[N];
int nt[N];

void getnext()
{
    int i = 0, j = -1;
    nt[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i ++, j ++;
            nt[i] = j;
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
    scanf("%d%s", &n, s);
    getnext();

    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int t = i;
        while (nt[t]) t = nt[t];
        if (nt[i]) nt[i] = t;
        ans += i - t;
    }
    printf("%lld\n", ans);

    return 0;
}
