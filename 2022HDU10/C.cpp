#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000005;

int n;
int a[N];
int b[N];

LL up()
{
    for (int i = 1; i <= n; i ++ )
        a[i] = b[i];
    LL res = 0;
    for (int i = 2; i <= n; i ++ )
        if (i % 2 == 0 && a[i] <= a[i - 1])
            res += a[i - 1] + 1 - a[i], a[i] = a[i - 1] + 1;
        else if(i % 2 && a[i] >= a[i - 1]) 
            res += a[i] - (a[i - 1] - 1), a[i] = a[i - 1] - 1;
    return res;
}

LL down()
{
    for (int i = 1; i <= n; i ++ )
        a[i] = b[i];
    LL res = 0;
    for (int i = 2; i <= n; i ++ )
        if (i % 2 == 0 && a[i] >= a[i - 1])
            res += a[i] - (a[i - 1] - 1), a[i] = a[i - 1] - 1;
        else if (i % 2 && a[i] <= a[i - 1])
            res += a[i - 1] + 1 - a[i], a[i] = a[i - 1] + 1;
    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &b[i]);
        
        printf("%lld\n", min(up(), down()));
    }
    return 0;
}