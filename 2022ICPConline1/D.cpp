#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int a[N];
int cnt;

void dfs(int cur, int num, int x)
{
    if (cur > 30) 
    {
        if (num == 0 && x <= 1e9) a[++ cnt] = x;
        return;
    }
    if (!num)
    {
        if (x <= 1e9) a[++ cnt] = x;
        return;
    }
    for (int i = 0; i < 2; i ++ )
    {
        if (x + (i << cur) <= 1e9)
            dfs(cur + 1, num - i, x + (i << cur));
    }
}

int main()
{

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    a[++ cnt] = 2;
    for (int i = 2; i <= 15; i ++ )
        dfs(i + 1, i - 1, 1 << i);
    sort(a + 1, a + 1 + cnt);
    // cout << cnt << endl;
    // for (int i = 1; i <= 100; i ++ )
    // {
    //     bitset<20> b(a[i]);
    //     cout << a[i] << " " << b << endl;
    // }

    int l, r;
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &l, &r);
        int pa = lower_bound(a + 1, a + 1 + cnt, l) - a;
        int pb = upper_bound(a + 1, a + 1 + cnt, r) - a - 1;
        if (pa <= pb)
            printf("%d\n", a[pa]);
        else puts("-1");
    }


    return 0;
}