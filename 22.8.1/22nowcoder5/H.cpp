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

const int N = 100005, mod = 1000000007;
const double pi = acos(-1);

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    while(~scanf("%d", &n))
    {
        double r = 1.0 * n / 2;
        double ans = r * r * 2 + pi / 2 * r * r;
        printf("%.10f\n", ans);
    }
    return 0;
}
