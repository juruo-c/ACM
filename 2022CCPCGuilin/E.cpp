#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

LL x1, y1, x2, y2;

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if (!b) 
    {
        x = 1, y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, x, y);
    LL z = x;
    x = y;
    y = z - y * (a / b);
    return g;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        LL a = -(y2 - y1), b = x2 - x1, x, y;
        int sgnx = 1, sgny = 1;
        if (a < 0)
        {
            sgnx = -1;
            a = -a;
        }
        if (b < 0)
        {
            sgny = -1;
            b = -b;
        }
        exgcd(a, b, x, y);
        x *= sgnx, y *= sgny;
        x += x1, y += y1;
        printf("%lld %lld\n", x, y);
    }
    return 0;
}