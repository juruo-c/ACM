#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, q;
LL a[N];
int last[N];
int now, val;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    scanf("%d", &q);
    for (int i = 1; i <= q; i ++ )
    {
        int op;
        scanf("%d", &op);
        int id, x;
        if (op == 1) 
        {
            scanf("%d", &x);
            now = i;
            val = x;
        }
        else if(op == 2)
        {
            scanf("%d%d", &id, &x);
            if (last[id] != now) a[id] = val, last[id] = now;
            a[id] += x;
        }
        else 
        {
            scanf("%d", &id);
            if (last[id] != now) a[id] = val, last[id] = now;
            printf("%lld\n", a[id]);
        }
    }

    return 0;
}