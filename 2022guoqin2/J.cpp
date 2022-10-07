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

typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100005;

int n;
char s[N];
ULL p[N], f[N], g[N];

ULL getf(int l, int r)
{
    return f[r] - f[l - 1] * p[r - l + 1];
}

ULL getg(int l, int r)
{
    return g[r] - g[l - 1] * p[r - l + 1];
}

bool check(int i)
{
    return getf(1, i) == getf(i + 1, 2 * i) && getf(2 * i + 1, n) == getg(1, n - 2 * i);
}

int solve()
{
    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = p[i - 1] * 13331;
        f[i] = f[i - 1] * 13331 + (s[i] - 'a' + 1);
    }
    reverse(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i ++ )
        g[i] = g[i - 1] * 13331 + (s[i] - 'a' + 1);
    reverse(s + 1, s + 1 + n);

    for (int i = 1; i <= n / 2; i ++ )
    {
        if (check(i))
        {
            return i + 1;
        }
    }
    return -1;
}

bool check1(int i)
{
    return getf(1, i) == getf(n - i + 1, n) && getf(i + 1, n - i) == getg(i + 1, n - i);
}

int del()
{
    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = p[i - 1] * 13331;
        f[i] = f[i - 1] * 13331 + (s[i] - 'a' + 1);
    }
    reverse(s + 1, s + 1 + n);
    for (int i = 1; i <= n; i ++ )
        g[i] = g[i - 1] * 13331 + (s[i] - 'a' + 1);
    reverse(s + 1, s + 1 + n);

    for (int i = 1; i <= n / 2; i ++ )
        if (check1(i))
            return i + 1;
    return -1;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int l = 1, r = n;
    while (l <= r && s[l] == s[r]) l ++, r --;
    if (l > r)
    {
        printf("%d %d\n", 1, n);
        return 0;
    }

    int tt = l - 1;
    n = r - l + 1;
    for (int i = 1, j = l; i <= n; i ++, j ++ )
        s[i] = s[j];

    int t;
    if ((t = solve()) != -1)
    {   
        printf("%d %d\n", t + tt, n + tt);
        return 0;
    }   
    if ((t = del()) != -1)
    {
        printf("%d %d\n", 1 + tt, t - 1 + tt);
        return 0;
    }
    reverse(s + 1, s + 1 + n);
    if ((t = solve()) != -1)
    {
        printf("%d %d\n", 1 + tt, n - t + 1 + tt);
        return 0;
    }
    puts("-1 -1");
    
    return 0;
}
