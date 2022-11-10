#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300005;

int n, k;
int a[N];
int m;
int realx[N];
int limit[N];
int realsz[N];
int pos0[N];
int cnt0;

struct Node
{
    int x, y;
    bool operator < (const Node& b) const 
    {
        return x < b.x;
    }
}node[N];

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {

        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= k; i ++ )
            scanf("%d%d", &node[i].x, &node[i].y);
        sort(node + 1, node + 1 + k);

        m = 0;
        if (!k || node[1].x != 0)
        {
            realx[++ m] = 0;
            limit[m] = n + 1;
        }
        else 
        {
            if (node[1].y != 0)
            {
                realx[++ m] = 0;
                limit[m] = node[1].y;
                int i = 2;
                while (i <= k && node[i].x == node[i - 1].x + 1 && node[i].y != 0)
                {
                    realx[++ m] = node[i].x;
                    limit[m] = node[i].y;
                    i ++;
                }
                if (i > k)
                {
                    realx[++ m] = node[k].x + 1;
                    limit[m] = n + 1;
                }
                else if (node[i].x != node[i - 1].x + 1)
                {
                    realx[++ m] = node[i - 1].x + 1;
                    limit[m] = n + 1;
                }
            }
        }

        for (int i = 1; i <= k; i ++ )
        {
            if (node[i].y == 0)
            {
                realx[++ m] = node[i].x;
                limit[m] = 0;
                int j = i + 1;
                while (j <= k && node[j].x == node[j - 1].x + 1 && node[j].y != 0)
                {
                    realx[++ m] = node[j].x;
                    limit[m] = node[j].y;
                    j ++;
                }
                if (j > k)
                {
                    realx[++ m] = node[k].x + 1;
                    limit[m] = n + 1;
                }
                else if (node[j].x != node[j - 1].x + 1)
                {
                    realx[++ m] = node[j - 1].x + 1;
                    limit[m] = n + 1;
                }
                i = j - 1;
            }
        }
        for (int i = 1; i <= m; i ++ )
            realsz[i] = 0;

        // puts("realx: ");
        // for (int i = 1; i <= m; i ++ )
        //     printf("%d ", realx[i]);
        // puts("");
        // puts("limit: ");
        // for (int i = 1; i <= m; i ++ )
        //     printf("%d ", limit[i]);
        // puts("");
        
        cnt0 = 0;
        for (int i = 1; i <= m; i ++ )
            if (limit[i] == 0 || realx[i] == 0) pos0[++ cnt0] = i;
        
        long long res = 0;
        int p0 = 1;
        int p = pos0[p0];
        for (int i = 1; i <= n; i ++ )
        {
            int t = a[i];
            int tmp_p0 = p0;
            while (p0 <= cnt0 && realx[pos0[p0]] <= t) p0 ++;
            p0 --;
            if (tmp_p0 != p0)
                p = pos0[p0];
            
            if (limit[p] == realsz[p]) p ++;
            res += t - realx[p];
            realsz[p] ++;
        }

        printf("%s\n", res & 1 ? "Pico" : "FuuFuu");
    }
    return 0;
}