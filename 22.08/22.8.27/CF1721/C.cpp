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

const int N = 200005;

int n;
int a[N];
int b[N];
int st[20][N];
int lg[N];

int query(int l, int r)
{
    int k = lg[r - l + 1];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

bool check(int i, int x)
{
    // cout << i << " " << x << " " << query(i, x - 1) << endl;
    return !query(i, x - 1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    for (int i = 2; i < N; i ++ ) lg[i] = lg[i / 2] + 1;
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);

        for (int i = 1; i <= n; i ++ )
        {
            int x = lower_bound(b + 1, b + 1 + n, a[i]) - b;
            printf("%d ", b[x] - a[i]);
        }
        puts("");

        for (int i = 1; i < n; i ++ )
            if (a[i + 1] <= b[i]) st[0][i] = 0;
            else st[0][i] = 1;

        for (int j = 1; j < 20; j ++ )
            for (int i = 1; i + (1 << j) - 1 < n; i ++ )
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    
        for (int i = 1; i <= n; i ++ )
        {
            int l = i, r = n;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (check(i, mid)) l = mid;
                else r = mid - 1;
            }
            // printf("l = %d\n", l);
            printf("%d ", b[l] - a[i]);
        }
        puts("");
    }
    return 0;
}
