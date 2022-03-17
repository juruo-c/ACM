//http://oj.daimayuan.top/course/10/problem/559

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 200005;

int n;
PII a[N];
int c[N];
int ans[N];

void update(int x)
{
    for (int i = x; i <= n; i += (i & -i))
        c[i] ++;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += c[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i].first), a[i].second = i;
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++ )
    {
        int t = a[i].second;
        for (int j = 1; j < n; j ++ )
        {
            if (j * (t - 1) + 2 <= n)
                ans[j] += query(min(n, j * t + 1)) - query(j * (t - 1) + 1);
            else break;
        }
        update(t);
    }

    for (int i = 1; i < n; i ++ )
        printf("%d ", ans[i]);

    return 0;
}
