#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n;
int a[N];

LL qpow(int a, int b, LL p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) 
            scanf("%d", &a[i]);
        
        bool flag = true;

        int M = 0;
        if (a[0] == 0)
        {
            M = 1;
            for (int i = 1; i < n; i ++ )
                if (a[i])
                {
                    flag = false;
                    break;
                }
        }
        else if (a[0] > 1)
            flag = false;
        else 
        {
            int i;
            for (i = 1; i < n; i ++ )
                if (a[i] != a[i - 1] * 2) 
                {
                    M = 2 * a[i - 1] - a[i];
                    break;
                }
            if (M <= a[i - 1]) flag = false;
            else 
            {
                for (int i = 1; i < n; i ++ )
                if (a[i] != a[i - 1] * 2 % M)
                {
                    flag = false;
                    break;
                }
            }
        }
        

        if (!flag)
            puts("-1");
        else printf("%d\n", M);
    }
    return 0;
}