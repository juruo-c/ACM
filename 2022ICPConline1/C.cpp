#include <iostream>

using namespace std;

const int N = 1000005;

int n;
int d[N];

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i  ++ )
            d[i] = 0;
        for (int i = 1; i < n; i ++ )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u] ++, d[v] ++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            if (d[i] == 1)
                ans ++;
        printf("%d\n", ans);
    }
    return 0;
}