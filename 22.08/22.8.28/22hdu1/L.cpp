#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

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
        int n;
        scanf("%d", &n);
        vector<int> a(n + 1);
        for (int i = 0; i <= n; i ++ ) scanf("%d", &a[i]);
        for (int i = n; i >= 1; i -- )
            a[i - 1] += a[i] / 2;
        if (a[0]) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
