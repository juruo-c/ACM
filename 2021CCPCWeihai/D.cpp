#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005;

int n, q;
char s[N];
int nt[N];
int f[N];

void getnext()
{
    nt[0] = -1;
    int i = 0, j = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j]) nt[++ i] = ++ j;
        else j = nt[j];
    }
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    getnext();

    int i = n;
    while (nt[i])
    {
        i = nt[i];
        f[n - i] ++;
    }

    for (int i = n - 1; i >= 0; i -- )
        f[i] += f[i + 1];

    scanf("%d", &q);
    for (int i = 1; i <= q; i ++ )
    {
        int x;
        scanf("%d", &x);
        x --;
        if (x < n / 2) printf("%d\n", f[n - x]);
        else printf("%d\n", f[x + 1]);
    }

    return 0;
}