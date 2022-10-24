#include <iostream>
#include <algorithm>
#include <cstring>
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
    while(_ --)
    {
        int n;
        scanf("%d", &n);
        if (n % 2)
        {
            printf("%d ", n);
            n --;
        }
        for (int i = n / 2; i >= 1; i -- )
            printf("%d %d ", i, i + n / 2);
        puts("");
    }

    return 0;
}