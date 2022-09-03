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

int cnt[30];

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
        if (m == 1)
        {
            printf("1\n1\n");
            continue;
        }
        int last;
        for (int i = 29; i >= 0; i -- ) 
            if (m >> i & 1) 
            {
                last = i;
                break;
            }
        
        int t = last;
        int n = 2 * last, ext = 0;
        for (int i = last - 1; i >= 0; i -- )
            if (m >> i & 1) 
                ext += t - i, cnt[i] = t - i, t = i;
        
        printf("%d\n", n + ext);
        int a = 1, b = n + 1;
        for (int i = 0; i < last; i ++ )
        {
            if (cnt[i])
            {
                for (int j = 0; j < cnt[i]; j ++ )
                    printf("%d ", b ++);
                cnt[i] = 0;
            }
            printf("%d %d ", a + 1, a);
            a += 2;
        }
        puts("");
    }
    return 0;
}

