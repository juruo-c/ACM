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
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        vector<LL> ans;
        bool ok = true;
        for (int i = 1; i <= n; i ++ )
        {
            if (r / i - (l - 1) / i <= 0) 
            {
                ok = false;
            }
            else 
                ans.push_back(1LL * ((l - 1) / i + 1) * i);
        }
        if (ok)
        {
            puts("YES");
            for (int i = 0; i < ans.size(); i ++ )
                printf("%d ", ans[i]);
            puts("");
        }
        else 
            puts("NO");
    }
    return 0;
}
