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

const int N = 100005;

struct Seq
{
    int l, r;
    bool operator < (const Seq& b) const 
    {
        if (l == b.l) return r < b.r;
        return l < b.l;
    }
}a[N];

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
        for (int i = 1; i <= n; i ++ )
            scanf("%d%d", &a[i].l, &a[i].r);
        sort(a + 1, a + 1 + n);

        int cur = a[1].r;
        int i = 2;
        for (; i <= n; i ++ )
        {
            if (a[i].l <= cur)
            {
                i --;
                break;
            }
            else cur = a[i].r;
        }
        i --;
        printf("%d\n", i);
    }
    return 0;
}
