#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ZYCMH

using namespace std;

typedef pair<int, int> PII;

const int N = 200005;

int n;
int a[N];
int ans[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

        int c1 = 0, c0 = 0;
        for (int i = 1; i <= n; i ++ )
            if (a[i] > 0) c1 ++;
            else if (a[i] < 0) c0 ++;

        if ((c1 + c0) % 2)
        {
            puts("-1");
            continue;
        }
        
        if (c0 > c1)
        {
            for (int i = 1; i <= n; i ++ )
                if (a[i] > 0) a[i] = -1;
                else if (a[i] < 0) a[i] = 1;
            swap(c1, c0);
        }
        else if(c0 == c1)
        {
            printf("%d\n", n);
            for (int i = 1; i <= n; i ++ )
                printf("%d %d\n", i, i);
            continue;
        }

        int i, k = c1 - c0;
        k /= 2;
        int cnt = 0;
        for (i = 2; i <= n; i ++ )
        {
            if (a[i] == 1 && a[i - 1] != 2)
                ans[++ cnt] = i - 1, a[i] = 2, k -- ;
            if (!k) break;
        }

        printf("%d\n", cnt + (n - cnt * 2));
        k = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (k <= cnt && i == ans[k])
            {
                printf("%d %d\n", i, i + 1);
                k ++, i ++;
            }
            else printf("%d %d\n", i, i);
        }

    }

    return 0;
}