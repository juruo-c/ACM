#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 505;

int n, m;
int a[N];
LL op[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &m);
        set<int> val;
        for (int i = 1; i <= n; i ++ ) 
        {
            scanf("%d", &a[i]);
            int x = a[i];
            while (x)
            {
                val.insert(x);
                x /= 2;
            }
        }
        
        LL ans = 1e18;
        for (auto h : val)
        {
            for (int i = 1; i <= n; i ++ )
            {
                int x = a[i];
                op[i] = 0;
                
                if (a[i] <= h) op[i] = h - a[i];
                else
                {
                    while (x / 2 >= h) op[i] ++, x /= 2;
                    op[i] += min(x - h, h - x / 2 + 1);
                }
            }
            sort(op + 1, op + 1 + n);
            LL res = 0;
            for (int i = 1; i <= n - m; i ++ )
                res += op[i];
            ans = min(res, ans);
        }
        printf("%lld\n", ans);

    }
    return 0;
}