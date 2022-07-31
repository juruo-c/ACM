#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        int num = 0, t = n;
        while (t)
        {
            num ++;
            t /= 10;
        }
        int ans = 0;
        for (int k = 1; k <= n; k ++ )
        {
            int c = 0;
            int i = 0, j = 1;
            while(true)
            {
                c ++;
                i = i * 10 + 9, j *= 10;
                int t = 1LL * i * k % n;
                if (t >= 1 && t <= j) break;
                if (!t && n >= 1 && n <= j) break;
            }

            ans += c;
        }
        printf("%d\n", ans);
    }
    return 0;
}
