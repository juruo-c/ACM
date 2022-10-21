#include <iostream>
#define ZYCMH

using namespace std;

const int N = 1000005;

int n;
char s[N];
char ans[N];
char t[N];

bool cmp(char* a, char* b)
{
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;
    }
    return false;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &n);
    scanf("%s", s + 1);

    int i;
    for (i = 1; i <= n; i ++ )
        if (s[i] == '1')
            break;
    
    if (i > n)
    {
        puts("0");
        return 0;
    }
        
    int j;
    for (j = i; j <= n; j ++ )
        if (s[j] == '0')
            break;
    
    if (j > n)
    {
        for (int k = i; k <= n; k ++ )
            printf("1");
        puts("");
        return 0;
    }

    for (int k = 1; k < j; k ++ )
        ans[k] = s[k], t[k] = s[k];

    for (int k = i; k <= j - 1; k ++ )
    {
        for (int p = j, q = k; p <= n; p ++, q ++)
            t[p] = (s[p] == '1' || s[q] == '1') ? '1' : '0';
        if (cmp(t, ans))
        {
            for (int p = j; p <= n; p ++)
                ans[p] = t[p];
        }
    }

    int k = 1;
    while (ans[k] == '0') k ++;
    for (; k <= n; k ++ )
        printf("%c", ans[k]);
    puts("");

    return 0;
}