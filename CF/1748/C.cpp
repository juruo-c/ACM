#include <bits/stdc++.h>
#define ZYCMH

using namespace std;

const int N = 200005;

typedef long long LL;

int n;
int a[N];
LL sum[N];
int p[N];
int cnt;

int solve(int l, int r)
{
    set<LL> s;
    map<LL, int> c;
    for (int i = l; i <= r; i ++ )
        s.insert(sum[i]), c[sum[i]] ++;
    
    int mx = 0;
    for (auto x : s)
        mx = max(mx, c[x]);
    return mx;
}

int main()
{

    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while (_ --)
    {
        cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) 
        {
            scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
            if (a[i] == 0) p[++ cnt] = i;
        } 
        p[++ cnt] = n + 1;

        int ans = 0;
        for (int i = 1; i < p[1]; i ++ )
            if (sum[i] == 0) ans ++;

        // for (int i = 1; i <= cnt; i ++ )
        //     cout << p[i] << " ";
        // cout << endl;

        for (int i = 1; i < cnt; i ++ )
            ans += solve(p[i], p[i + 1] - 1);

        printf("%d\n", ans);
    }

    return 0;
}