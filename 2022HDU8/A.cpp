#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
char s[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int p1, p2;

        int i;
        for (i = n; i >= 1; i -- )
            if (s[i] == '1') 
            {
                if ((n - i) % 2 == 0)
                {
                    p1 = n;
                    p2 = 1;
                }
                else p1 = n - 1, p2 = 0;
                break;
            }

        // cout << p1 << " " << p2 << endl;
        
        if (!i) 
        {
            printf("%s\n", s + 1);
            continue;
        }

        i --;
        for (; i >= 1; i -- )
        {
            if (s[i] == '1')
            {
                // cout << i << " ";
                if ((p1 - i - 1) % 2 == 0)
                {
                    if (n - p1 + 1 == p2) p1 --, p2 ++;
                    else p2 += 2;
                }
                else
                    p1 -= 2;
                // cout << p1 << " " << p2 << endl;
            }
        }

        // cout << p1 << " " << p2 << endl;

        for (int i = 1; i < p1; i ++ )
            putchar('0');
        for (int i = 0; i < (n - p1 + 1 - p2) / 2; i ++ )
            putchar('1'), putchar('0');
        for (int i = 0; i < p2; i ++ )
            putchar('1');
        puts("");
        
    }
    return 0;
}