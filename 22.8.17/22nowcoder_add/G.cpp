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

const int N = 300005, mod = 1000000007;

char s[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        // printf("n = %d\n", n);
        int rc = n / 3, ec = n / 3, dc = n / 3;
        for (int i = 1; i <= n; i ++ )
            if (s[i] == '?')
            {
                if (rc) s[i] = 'r', rc --;
                else if(ec) s[i] = 'e', ec --;
                else s[i] = 'd', dc --;
            }
            else if(s[i] == 'r') rc --;
            else if(s[i] == 'e') ec --;
            else if(s[i] == 'd') dc --;

        rc = 0, ec = 0, dc = 0;
        bool flag = true;

        // printf("%s\n", s + 1);

        for (int i = 1; i <= n; i ++ )
        {
            if (s[i] == 'r') rc ++;
            else if(s[i] == 'e') ec ++;
            else dc ++;
            if (rc < ec || ec < dc) 
            {
                flag = false;
                break;
            }
        }

        if (flag) puts("Yes");
        else puts("No");

    }
    return 0;
}
