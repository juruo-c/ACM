#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 500005;

int n;
int x[N], y[N];

bool judge(int x1, int y1, int xx, int yy)
{
    if (xx == x1 || yy == y1 || x1 - xx == yy - y1 || x1 - xx == y1 - yy) return true;
    return false;
}

bool check(int cx, int cy)
{
    for (int i = 1; i <= n; i ++ )
        if (!judge(cx, cy, x[i], y[i]))
            return false;
    return true;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%d%d", &x[i], &y[i]), x[i] *= 2, y[i] *= 2;

        bool flag = true;
        int x1 = x[1], y1 = y[1], x2, y2;
        for (int i = 2; i <= n; i ++ )
        {
            if (!judge(x1, y1, x[i], y[i]))
            {
                flag = false;
                x2 = x[i], y2 = y[i];
                break;
            }
        }

        // cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = " << x2 << " " << "y2 = " << y2 << endl;

        if (flag) puts("YES");
        else 
        {
            if (check(x2, y1)) flag = true;
            if (check(x2 + y2 - y1, y1)) flag = true;
            if (check(y1 + x2 - y2, y1)) flag = true;
            if (check(x1, y2)) flag = true;
            if (check(x1, x2 - x1 + y2)) flag = true;
            if (check(x1, x1 - x2 + y2)) flag = true;
            if (check(x1 + y1 - y2, y2)) flag = true;
            if (check(x2, x1 - x2 + y1)) flag = true;
            if (check((x1 + x2 - y2 + y1) / 2, (x1 + x2 - y2 + y1) / 2 - x2 + y2)) flag = true;
            if (check(y2 + x1 - y1, y2)) flag = true;
            if (check(x2, x2 - x1 + y1)) flag = true;
            if (check((x2 + y2 + x1 - y1) / 2, (x2 + y2 + x1 - y1) / 2 - x1 + y1)) flag = true;
            if (flag) puts("YES");
            else puts("NO");
        }

    }
    return 0;
}
