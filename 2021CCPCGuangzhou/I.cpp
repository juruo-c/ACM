#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 998244353;

int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
            int n;
        scanf("%d", &n);
        if (n == 1) puts("1");
        else if (n == 2) puts("2");
        else if (n == 3) puts("6");
        else 
            printf("%d\n", 1LL * 6 * qpow(2, n - 3) % mod);
    }
}