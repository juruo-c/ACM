#include <bits/stdc++.h>
#define ZYCMH

using namespace std;

const int N = 1000005;

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
        printf("%d\n", (n + 1) / 2);
    }

    return 0;
}