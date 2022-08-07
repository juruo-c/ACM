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

const int N = 300005, mod = 1000000007;

int ans[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    vector<int> num;
    for (int i = 0; i * i < N; i ++ )
        num.push_back(i * i);
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        int t = n - 1;
        while (t >= 0)
        {
            int i;
            for (i = 0; i < num.size(); i ++ )
                if (num[i] >= t) break;
            int x = num[i];
            for (int j = t; j >= x - t; j -- )
                ans[j] = x - j;
            t = x - t - 1;
        }

        for (int i = 0; i < n; i ++ )
        {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
