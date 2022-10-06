#include <iostream>
#define ZYCMH

using namespace std;

typedef long long LL;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int B, R, D, S;
        scanf("%d%d%d%d", &B, &R, &D, &S);
        if (R == 0)
        {
            if (D)
                puts("gua!");
            else puts("ok");
            continue;
        }
        LL t = S * R / 60 + 1;
        t *= B;
        if (D <= t)
            puts("ok");
        else puts("gua!");
    }
    return 0;
}