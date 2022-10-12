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

const int N = 262500;

int p[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++ )
            scanf("%d", &p[i]);

        bool flag = true;
        int ans = 0;
        for (int i = 0; (1 << i) < m; i ++ )
        {
            int t = 1 << (i + 1);
            for (int j = 1; j <= m; j += t)
                if (abs(p[j] - p[j + t / 2]) != t / 2)
                {
                    flag = false;
                    break;
                }
            if (!flag) break;
            // cout << "i = " << i << endl;

            int len = 1 << i;
            for (int j = 1; j + len <= m; j += t )
            {
                if (p[j] > p[j + len])  ans ++, swap(p[j], p[j + len]);
            }
            
            // for (int j = 1; j <= m; j ++ )
            //     cout << p[j] << " ";
            // cout << endl;
        }

        printf("%d\n", flag ? ans : -1);

    }
    return 0;
}
