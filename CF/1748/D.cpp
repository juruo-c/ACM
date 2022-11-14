#include <bits/stdc++.h>
#define ZYCMH

using namespace std;

const int N = 200005;

typedef long long LL;

int main()
{

    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        a |= b;

        int i = 0, j = 0;
        while (!(d >> i & 1)) i ++;
        while (!(a >> j & 1)) j ++;

        if (i > j) 
        {
            puts("-1");
            continue;
        }

        LL x = 0;
        for (int k = 0; k < 30; k ++ )
            if ((a >> k & 1) && !(x >> k & 1))
                x += (1LL * d) << (k - i);

        printf("%lld\n", x);
    }

    return 0;
}