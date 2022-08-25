#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
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
        int n;
        scanf("%d", &n);
        vector<int> a(n);   
        int s = 0;
        LL sum = 0;
        for (int i = 0; i < n; i ++ )
        {
            scanf("%d", &a[i]);
            s ^= a[i];
            sum += a[i];
        }

        if (s)
        {
            int mx = 0, cnt = 1;
            for (int i = 0; i < n; i ++ )
                if (a[i] > (a[i] ^ s))
                {
                    int dif = a[i] - (a[i] ^ s);
                    if (dif > mx)
                    {
                        mx = dif;
                        cnt = 1;
                    }
                    else if(dif == mx)
                        cnt ++;
                }
            printf("%lld %d\n", sum - mx, cnt);
        }
        else 
        {
            vector<bool> bit(true);
            for (int i = 0; i < n; i ++ )
            {
                for (int j = __lg(a[i] & -a[i]) + 1; j < 30; j ++ )
                    if (a[i] & (1 << j))
                        bit[j] = false;
            }

            int cnt = 0;
            for (int i = 0; i < n; i ++ )
                if (!bit[__lg(a[i] & -a[i])])
                    cnt ++;
            
            printf("%lld %d\n", sum, cnt);
        }

    }
    return 0;
}
