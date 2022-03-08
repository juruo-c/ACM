//http://oj.daimayuan.top/course/10/problem/497
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 300005, M = 32;

int n;
int a[N];
int ch[N * M][2], cnt;
int id[N][M];
int s1[N * M], s0[N * M];

void add(int e, int x)
{
    int u = 0;
    for (int i = 31; i >= 0; i -- )
    {
        int v = x >> i & 1;
        if (ch[u][v] == 0) ch[u][v] = ++ cnt;
        u = ch[u][v];
        id[e][i] = u;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        add(i, a[i]);
    }

    LL ans = 0;
    int x = 0;
    for (int i = 31; i >= 0; i -- )
    {
        LL c1 = 0, c0 = 0;
        for (int j = 1; j <= n; j ++ )
        {
            int t = id[j][i + 1];
            if (a[j] & (1 << i))
                c1 += s0[t], s1[t] ++;
            else c0 += s1[t], s0[t] ++;
        }

        if (c1 < c0) ans += c1, x += 1 << i;
        else ans += c0;
    }

    printf("%lld %d", ans, x);

    return 0;
}
