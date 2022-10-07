#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _;scanf("%d", &_);
    while (_ --)
    {
        double n;
        double c;
        scanf("%lf%lf", &n, &c);
        if (n >= 10000000) c += 2.0;
        else if (n <= 9800000) c += (n - 9500000) / 300000;
        else c += 1.0+(n - 9800000)/200000;
        printf("%.10f\n", max(0.0, c));
    }
    return 0;
}