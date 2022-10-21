#include <iostream>
#define ZYCMH

using namespace std;

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
        int n;
        scanf("%d", &n);
        int a;
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a);
        n = 10 - n;
        printf("%d\n", n * (n - 1) / 2 * 6);
    }

    return 0;
}