#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
LL gcd(LL a, LL b)
{
    return !b? a : gcd(b, a % b);
}
LL pow2[64];
int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _;scanf("%d", &_);
    pow2[0] = 1;
    for(int i = 1; i < 64; i ++) pow2[i] = pow2[i - 1] * 2;
    while (_ --)
    {
        LL x, y;
        int a, b;
        scanf("%lld%lld%d%d", &x, &y, &a, &b);
        LL tmp = gcd(x, y);
        x /= tmp, y /= tmp;
        x += y;
        int ans = -1;
        for(int i = 0; i < 64; i ++) 
        {
            if(pow2[i] == x) 
            {
                ans = i + 1; break;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}