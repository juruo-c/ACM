//https://www.acwing.com/problem/content/248/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
LL a[N];
LL c[N];

void add(int x, LL k)
{
    for (int i = x; i <= n; i += (i & -i) )
        c[i] += k;
}

LL query(int x)
{
    LL res = 0;
    for (int i = x; i; i -= (i & -i) )
        res += c[i];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%lld", &a[i]);
        add(i, a[i] - a[i - 1]);
    }

    while (m -- )
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'C')
        {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            add(l, d);
            add(r + 1, -d);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", query(x));
        }
    }
    return 0;
}
