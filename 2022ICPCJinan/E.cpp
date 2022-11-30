#include<bits/stdc++.h>
using namespace std;
int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k % 2 == 0) puts("Yes");
        else 
        {
            if (k == 1)
            {
                if (n == 1) puts("Yes");
                else puts("No");
            }
            else 
            {
                int a = n % k, b = n / k - (n % 2);
                if ((a + b) % 2) puts("No");
                else 
                {
                    int x = (a + b) / 2;
                    int y = x - b;
                    if (x >= 0 && y >= 0 && x <= k / 2) puts("Yes");
                    else puts("No");
                }
            }
        }
    }

    return 0;
}