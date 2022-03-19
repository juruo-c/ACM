#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 20;

LL a, b;
int na, nb;
int numa[N], numb[N];
int cnt[10];

int main()
{
    cin >> a >> b;
    LL t = a;
    while (t)
    {
        numa[na ++ ] = t % 10;
        t /= 10;
    }
    t = b;
    while (t)
    {
        numb[nb ++ ] = t % 10;
        t /= 10;
    }

    LL ansa = (1LL << 63) - 1, ansb;
    for (int i = 0; i < (1 << na); i ++ )
    {
        for (int j = 0; j < 10; j ++ ) cnt[j] = 0;
        __int128 ap = 0;
        for (int j = na - 1; j >= 0; j -- )
            if (i & (1 << j)) ap = ap * 10 + numa[j];
            else cnt[numa[j]] ++;

        if (!ap) continue;
        if ((ap * b) % a) continue;
        __int128 bp = ap * b / a;
        LL tmp = bp;

        for (int j = 0; j < nb; j ++ )
        {
            if (tmp % 10 != numb[j]) cnt[numb[j]] --;
            else tmp /= 10;
        }
        if (tmp) continue;

        bool flag = false;
        for (int j = 0; j < 10; j ++ ) if (cnt[j]) flag = true;

        if (flag) continue;

        if (ap < ansa) ansa = ap, ansb = bp;
    }

    printf("%lld %lld\n", ansa, ansb);
    return 0;
}
