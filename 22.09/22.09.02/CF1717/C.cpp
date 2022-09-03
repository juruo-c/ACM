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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i ++ )
            scanf("%d", &b[i]);
        
        bool flag = true;
        for (int i = 0; i < n; i ++ )
            if (a[i] != b[i])
            {
                flag = false;
                break;
            }

        if (flag)
        {
            puts("YES");
            continue;
        }

        flag = true;
        for (int i = 0; i < n; i ++ )
            if (a[i] > b[i])
            {
                flag = false;
                break;
            }
        
        if (!flag) 
        {
            puts("NO");
            continue;
        }

        flag = true;
        for (int i = 0; i < n; i ++ )
            if (a[i] != b[i])
            {
                // cout << a[i] << " " << b[i] << endl;
                if (b[i] - b[(i + 1) % n]>= 2)
                {
                    flag = false;
                    break;
                }
            }

        if (flag) puts("YES");
        else puts("NO");    

    }
    return 0;
}
