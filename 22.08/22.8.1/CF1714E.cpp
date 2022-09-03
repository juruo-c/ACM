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

const int N = 200005, mod = 1000000007;

int n;
int a[N];
int flag[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);

        set<int> s;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &a[i]);
            int t1 = a[i] % 10, t2 = a[i] / 10 % 10;
            if (t1 == 1 || t1 == 2 || t1 == 4 || t1 == 8)
            {
                if (t2 % 2) flag[i] = 2;
                else flag[i] = 1;
            }
            else if (t1 == 3 || t1 == 6 || t1 == 7 || t1 == 9)
            {
                if (t2 % 2) flag[i] = 1;
                else flag[i] = 2;
            }
            else flag[i] = 3;
            s.insert(flag[i]);
        }

        if (s.size() > 1) puts("NO");
        else 
        {
            if (s.count(3))
            {
                set<int> s1;
                for (int i = 1; i <= n; i ++ )
                {
                    if (a[i] % 10 == 5) a[i] += 5;
                    s1.insert(a[i]);
                }
                if (s1.size() == 1) puts("YES");
                else puts("NO");
            }
            else puts("YES");
        }

    }
    return 0;
}
