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

const int N = 200005;

int n;
char s[N];
int cnt[10];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        for (int i = 0; i < 10; i ++ )
            cnt[i] = 0;
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int last = 0;
        for (int i = 0; i <= 9; i ++ )
        {
            int j = n;
            for (; j >= last + 1; j -- )
                if (s[j] == i + '0')
                    break;
            
            if (j >= last + 1)
            {
                for (int k = last + 1; k <= j; k ++ )
                    if (s[k] == i + '0')
                        cnt[i] ++;
                    else cnt[min(s[k] - '0' + 1, 9)] ++;
                last = j;
            }
        }

        for (int i = 0; i < 10; i ++ )
            for (int j = 1; j <= cnt[i]; j ++ )
                printf("%c", '0' + i);
        puts("");

    }
    return 0;
}
