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

const int N = 100005, mod = 1000000007;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 13 * n + 19; i ++ ) putchar('*');
    puts("");
    for (int i = 2; i <= 4 * n + 4; i ++ )
    {
        if (i <= n + 1 || i > 3 * n + 4) 
        {   
            putchar('*');
            for (int j = 1; j < 13 * n + 18; j ++ )
                putchar('.');
            putchar('*');
        }
        else 
        {
            putchar('*');
            for (int j = 1; j <= n + 1; j ++ )
                putchar('.');
            putchar('@');
            if (i == n + 2 || i == 3 * n + 4)
                for (int j = 1; j <= 2 * n + 1; j ++ )
                    putchar('.');
            else 
            {
                for (int j = 0; j < i - (n + 3); j ++ )
                    putchar('.');
                putchar('@');
                for (int j = 0; j < 3 * n - i + 3; j ++ )
                    putchar('.');
            }
            putchar('@');

            for (int j = 1; j <= n + 1; j ++ )
                putchar('.');

            putchar('@');
            if (i == n + 2 || i == 2 * n + 3)
                for (int j = 1; j <= 2 * n + 2; j ++ )
                    putchar('@');
            else 
                for (int j = 1; j <= 2 * n + 2; j ++ )
                    putchar('.');

            for (int j = 1; j <= n + 1; j ++ )
                putchar('.');
            
            putchar('@');
            if (i == 3 * n + 4)
                for (int j = 1; j <= 2 * n + 2; j ++ )
                    putchar('@');
            else 
                for (int j = 1; j <= 2 * n + 2; j ++ )
                    putchar('.');
            
            for (int j = 1; j <= n + 1; j ++ )
                putchar('.');

            if (i == n + 2 || i == 2 * n + 3 || i == 3 * n + 4)
                for (int j = 1; j <= 2 * n + 3; j ++ )
                    putchar('@');
            else 
            {
                if (i < 2 * n + 3)
                {
                    putchar('@');
                    for (int j = 1; j <= 2 * n + 2; j ++ )
                        putchar('.');
                }
                else 
                {
                    for (int j = 1; j <= 2 * n + 2; j ++ )
                        putchar('.');
                    putchar('@');
                }
            }

            for (int j = 1; j <= n + 1; j ++ )
                putchar('.');

            putchar('*');

        }
        puts("");
    }
    for (int i = 1; i <= 13 * n + 19; i ++ ) putchar('*');
    puts("");
    return 0;
}
