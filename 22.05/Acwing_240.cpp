#include <iostream>

using namespace std;

const int N = 50005;

int n, k;
int fa[3 * N];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i ++ ) fa[i] = i;

    int ans = 0;
    for (int i = 1; i <= k; i ++ )
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || (d == 2 && x == y))
        {
            ans ++;
            continue;
        }

        if (d == 1)
        {
            if (getf(x + n) == getf(y) || getf(x) == getf(y + n))
            {
                ans ++;
                continue;
            }
            fa[getf(x)] = getf(y);
            fa[getf(x + n)] = getf(y + n);
            fa[getf(x + 2 * n)] = getf(y + 2 * n);
        }
        else
        {
            if (getf(x) == getf(y) || getf(x + n) == getf(y))
            {
                ans ++;
                continue;
            }
            fa[getf(x)] = getf(y + n);
            fa[getf(x + n)] = getf(y + 2 * n);
            fa[getf(x + 2 * n)] = getf(y);
        }
    }

    printf("%d", ans);

    return 0;
}
