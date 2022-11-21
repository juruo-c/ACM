#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, q, m;
int R[N];
int a[N], b[N], p[N];
int f[N][20];
LL sum[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &q);
        m = 0;
        memset(R, 0, sizeof R);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        for (int i = 1; i < n; i ++ )
            if (a[i] > a[i + 1])
                b[++ m] = a[i], p[m] = i;
        b[m + 1] = n + 1;
        p[m + 1] = n + 1;
        R[n + 1] = n + 1;

        stack<int> stk;
        stk.push(m + 1);
        for (int i = m; i >= 1; i -- )
        {
            while (b[stk.top()] < b[i]) stk.pop();
            R[p[i]] = p[stk.top()];
            stk.push(i);
        }

        for (int i = 1; i <= n + 1; i ++ )
            sum[i] = sum[i - 1] + R[i];

        for (int i = 1; i <= n + 1; i ++ )
            if (R[i]) f[i][0] = R[i];
        
        for (int j = 1; j < 20; j ++ )
            for (int i = 1; i + (1 << j) - 1 <= n + 1; i ++ )  
                if (R[i])
                    f[i][j] = f[f[i][j - 1]][j - 1];

        // for (int j = 1; j < 20; j ++ )
        //     for (int i = 1; i + (1 << j) - 1 <= n + 1; i ++ )
        //         cout << "j = " << j << " i = " << i << " f[i][j] = " << f[i][j] << endl;

        for (int i = 1; i <= q; i ++ )
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l == r) 
            {
                puts("0");
                continue;
            }

            int L = l, R = n + 1;
            while (L < R)
            {
                int mid = (L + R) >> 1;
                if (sum[mid] - sum[l - 1]) R = mid;
                else L = mid + 1;
            }
            if (R >= r) 
            {
                puts("0");
                continue;
            }

            int ans = 0;
            for (int j = 19; j >= 0; j -- )
                if (f[R][j] && f[R][j] <= r - 1) R = f[R][j], ans += 1 << j;

            printf("%d\n", ans + 1);
        }

    }
    return 0;
}