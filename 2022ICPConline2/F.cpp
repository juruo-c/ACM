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
        LL k, x, y;
        scanf("%lld%lld%lld", &k, &x, &y);
        vector<LL> powk;
        LL t = 1;
        while (t < max(x, y))
        {
            powk.push_back(t);
            LL tt = t;
            t *= (1 + k);
            if (t / (1 + k) != tt) break;
        }

        // for (int i = 0; i < powk.size(); i ++ )
        //     cout << powk[i] << " ";
        // cout << endl;

        
        // cout << px << " " << py << endl;

        vector<LL> a, b;
        while (x != 1)
        {
            a.push_back(x);
            int px = lower_bound(powk.begin(), powk.end(), x) - powk.begin() - 1;
            x = (x - powk[px] - 1) / k + 1;
        }
        a.push_back(1);
        while (y != 1)
        {
            b.push_back(y);
            int py = lower_bound(powk.begin(), powk.end(), y) - powk.begin() - 1;
            y = (y - powk[py] - 1) / k + 1;
        }
        b.push_back(1);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // for (int i = 0; i < a.size(); i ++ )
        //     cout << a[i] << " ";
        // cout << endl;
        // for (int i = 0; i < b.size(); i ++ )
        //     cout << b[i] << " ";
        // cout << endl;

        int i = 0, j = 0;
        int asz = a.size(), bsz = b.size();

        for (; i < asz && j < bsz; j ++, i ++ )
            if (a[i] != b[j])
                break;
        
        printf("%lld\n", a[i - 1]);
    }
    return 0;
}
