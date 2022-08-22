#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

vector<int> pos[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            pos[i].clear();
        
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            scanf("%d", &x);
            pos[x].push_back(i);
        }

        for (int i = 1; i <= n; i ++ )
        {
            int last = -1, cur = 0;
            for (int j = 0; j < pos[i].size(); j ++ )
            {
                int t = pos[i][j];
                if (last == -1)
                    cur = 1;
                else 
                {
                    if ((t - last - 1) % 2 == 0)
                        cur ++;
                }
                last = t;
            }
            if (i > 1) printf(" ");
            printf("%d", cur);
        }
        puts("");

    }
    return 0;
}
