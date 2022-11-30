#include <iostream>
#include <cstring>

using namespace std;

int ans[105];
int t[105];
int sum[105];
int n;

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        memset(ans, 0, sizeof ans);
        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            scanf("%d", &x);
            memset(t, 0, sizeof t);
            while (x)
            {
                t[++ t[0]] = x % 10;
                x /= 10;
            }

            int c = 0;
            sum[0] = max(ans[0],t[0]);
            for (int j = 1; j <= sum[0]; j ++ )
            {
                sum[j] = (ans[j] + t[j] + c);
                c = sum[j] / 10;
                if (c) res ++;
                sum[j] %= 10;
            }
            if (c) sum[++ sum[0]] = c;
            ans[0] = sum[0];
            for (int i = 1; i <= ans[0]; i ++ )
                ans[i] = sum[i];
        } 
        printf("%d\n", res);
    }
    return 0;
}