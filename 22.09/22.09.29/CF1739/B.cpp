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

const int N = 105;

int n;
int d[N];
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &d[i]);
        a[1] = d[1];
        bool flag = true;
        for (int i = 2; i <= n; i ++ )
        {
            if (!d[i])
            {
                a[i] = a[i - 1];
                continue;
            }
            int t1 = a[i - 1] + d[i];
            int t2 = a[i - 1] - d[i];
            
            if (t1 >= 0 && t2 >= 0) 
            {
                flag = false;
                break;
            }
            if (t1 >= 0) a[i] = t1;
            else a[i] = t2;
        }

        if (!flag) 
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i ++ )
            printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
