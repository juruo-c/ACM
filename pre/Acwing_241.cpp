//https://www.acwing.com/problem/content/243/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int y[N];
int c[N];
int l[N], r[N];

void add(int x)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] ++;
}

int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= (i & -i))
        ans += c[i];
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &y[i]);

    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        l[i] = (i - 1) - query(y[i]);
        add(y[i]);
    }
    memset(c, 0, sizeof c);
    for (int i = n; i >= 1; i -- )
    {
        r[i] = (n - i) - query(y[i]);
        ans += 1LL * l[i] * r[i];
        add(y[i]);
    }

    LL res = 0;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i ++ )
    {
        l[i] = query(y[i] - 1);
        add(y[i]);
    }
    memset(c, 0, sizeof c);
    for (int i = n; i >= 1; i --)
    {
        r[i] = query(y[i] - 1);
        res += 1LL * l[i] * r[i];
        add(y[i]);
    }


    printf("%lld %lld\n", ans, res);

    return 0;
}
