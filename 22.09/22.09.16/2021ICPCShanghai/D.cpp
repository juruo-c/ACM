#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        LL p, q;
        scanf("%lld%lld", &p, &q);
        LL t = p * p - 4 * q * q;
        LL sq = sqrt(t);
        if(sq * sq == t) cout << p + sq << " " << 2 * q << endl;
        else cout << "0 0" << endl;
    }
    return 0;
}
