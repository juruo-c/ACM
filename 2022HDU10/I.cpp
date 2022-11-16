#include <bits/stdc++.h>

using namespace std;

char s[10];
int a[105], b[105];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d%s", &n, s);
        n --;
        int t = n / 7 * 3 + 1;
        n %= 7;
        if (s[0] == 'A' && n > 2) t ++;
        if(s[0] == 'A' && n > 4) t ++;
        if (s[0] == 'B' && n > 1) t ++;
        if(s[0] == 'B' && n > 3) t ++;
        printf("%d\n", t);
    }
    // a[1] = b[1] = a[2] = b[2] = 1;
    // a[3] = 1, b[3] = 2;
    // a[4] = 2, b[4] = 2;
    // for (int i = 5; i <= 100; i ++ )
    //     a[i] = b[i - 3] + 1, b[i] = a[i - 4] + 2;
    
    // for (int i = 1; i <= 100; i ++ )
    //     printf("i = %d a = %d b = %d\n", i, a[i], b[i]);
    return 0;
}