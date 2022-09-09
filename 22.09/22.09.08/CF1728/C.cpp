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

const int N = 200005;

int n;
int a[N], b[N];
map<int, int> cnta, cntb;

int change(int x)
{
    int res = 0;
    while (x)
        x /= 10, res ++;
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        cnta.clear();
        cntb.clear();
     
        vector<int> c, d;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]), cnta[a[i]] ++;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &b[i]);
            cntb[b[i]] ++;
            if (cntb[b[i]] > cnta[b[i]])
                d.push_back(b[i]);
        }
        cnta.clear();
        for (int i = 1; i <= n; i ++ )
        {
            cnta[a[i]] ++;
            if (cnta[a[i]] > cntb[a[i]])
                c.push_back(a[i]);
        }

        int ca[15] = {0};
        int cb[15] = {0};
        n = c.size();
        int ans = 0;
        for (int i = 0; i < n; i ++ )
        {
            if (c[i] >= 10) ans ++, c[i] = change(c[i]);
            ca[c[i]] ++;
            if (d[i] >= 10) ans ++, d[i] = change(d[i]);
            cb[d[i]] ++;
        }

        for (int i = 2; i < 10; i ++ )
            ans += max(ca[i], cb[i]) - min(ca[i], cb[i]);
        
        printf("%d\n", ans);

    }
    return 0;
}
