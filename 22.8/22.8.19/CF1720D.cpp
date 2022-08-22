#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 300005;

int n;
int a[N];
int ch[N * 30][2], cnt = 1, val[N * 30][2];

void add(int x, int y, int k)
{
    int u = 1;
    for (int i = 29; i >= 0; i -- )
    {
        int t = x >> i & 1;
        if (!ch[u][t]) ch[u][t] = ++ cnt;
        u = ch[u][t];
        val[u][y >> i & 1] = max(val[u][y >> i & 1], k);
    }
}

int query(int x, int y)
{
    int mx = 0;
    int u = 1;
    for (int i = 29; i >= 0 && u; i -- )
    {
        int t = x >> i & 1;
        if (ch[u][t ^ 1])
            mx = max(mx, val[ch[u][t ^ 1]][(y >> i & 1) ^ 1]);
        u = ch[u][t];
    }
    return mx + 1;
}

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
        for (int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        
        cnt = 1;
        for (int i = 1; i <= 30 * n; i ++ )
            ch[i][0] = ch[i][1] = val[i][0] = val[i][1] = 0;

        int ans = 0;
        for (int i = 0; i < n; i ++ )
        {
            int t = query(a[i] ^ i, a[i]);
            ans = max(ans, t);
            add(a[i] ^ i, i, t);
        }
        printf("%d\n", ans);

    }
    return 0;
}
