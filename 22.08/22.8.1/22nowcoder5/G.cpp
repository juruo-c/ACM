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
char ma[N * 2];
int r[N * 2];
LL c[N * 2];

void Manacher()
{
    int l = 0;
    ma[l ++] = '$';
    ma[l ++] = '#';
    for (int i = 0; i < n; i ++ )
        ma[l ++] = s[i], ma[l ++] = '#';
    ma[l] = 0;

    int mx = 0, id = 0;
    for (int i = 0; i < l; i ++ )
    {
        r[i] = mx > i ? min(r[id * 2 - i], mx - i) : 1;
        while (ma[i + r[i]] == ma[i - r[i]]) r[i] ++;
        if (i + r[i] > mx) mx = i + r[i], id = i;
    }
}

LL calc(char ch)
{
    LL ans = 0;
    for (int i = 0; i < 2 * n + 2; i ++ )
        if (ma[i] == ch)
            ans += c[i];
    return ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    while (~scanf("%d", &n))
    {
        scanf("%s", s);
        Manacher();
        for (int i = 0; i < 2 * n + 2; i ++ )
        {
            int L = max(0, i - r[i] + 1);
            c[L] ++, c[i + 1] --;
        }

        for (int i = 1; i < 2 * n + 2; i ++ )
            c[i] += c[i - 1];

        printf("%lld %lld %lld\n", calc('k'), calc('f'), calc('c'));

    }
    return 0;
}
