#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100005, M = 3000, mod = 998857459;

int n, m;
int jc[N];
struct Node
{
    int p, val;
}a[N];
int cnt;
int mx[N];
int sum[N];
struct HNode
{
    int val, num;
}b[N];
int c[N], d[N];
int mi[N];

bool cmp(HNode& a, HNode& b)
{
    return a.val < b.val;
}

int main()
{
    scanf("%d%d", &n, &m);

    jc[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;
    
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        if (jc[x])
            a[++ cnt] = {i, jc[x]};
    }

    for (int i = 1; i <= cnt; i ++ )
        sum[i] = (sum[i - 1] + a[i].val) % mod; 

    for (int i = 1; i <= cnt; i ++ )
        for (int j = i; j <= cnt; j ++ )
        {
            int l = a[i].p, r = a[j].p;
            int len = r - l + 1;
            mx[len] = max(mx[len], (sum[j] - sum[i - 1] + mod) % mod);
        }


    for (int i = 1; i <= m; i ++ )
    {
        int k;
        scanf("%d", &k);
        int j;
        for (j = 1; j <= n; j ++ )
            if (mx[j] >= k) break;
        if (j > n) puts("-1");
        else printf("%d\n", j);
    }


    return 0;
}