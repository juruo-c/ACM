#include <bits/stdc++.h>

using namespace std;

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int ans = 0;
        for (int i = 0; i < n; i ++ )
        {
            int t = k / (n / (i + 1));
            if (k % (n / (i + 1))) t ++;
            if (m / t - 1 >= 0)
                ans = max(ans, i + m / t - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}