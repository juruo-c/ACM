#include <iostream>

using namespace std;

const int N = 100005;

int n;
int a[32];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= 30; i ++ )
            a[i] = 0;
        
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            scanf("%d", &x);
            for (int j = 0; j <= 30; j ++ )
                if (x >> j & 1)
                    a[j] ++;
        }

        int sum = 0;
        for (int i = 0; i <= 30; i ++ )
            sum += a[i];
        int ans = 0;

        while(sum)
        {
            ans ++;
            for (int i = 0; i <= 30; i ++ )
            {
                if (a[i]) a[i] --, sum --;
                else 
                {
                    int j;
                    for (j = i + 1; j <= 30; j ++ )
                        if (a[j]) break;
                    if (j > 30)
                        break;
                    a[j] --, sum --;
                    for (int k = i; k < j; k ++ )
                        a[k] ++, sum ++;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}