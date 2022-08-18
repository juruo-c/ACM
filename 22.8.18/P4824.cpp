#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000005;

int n, m;
char s[N], t[N];
int nt[N];
int stk[N], top;
int match[N];

void getnext()
{
    int i = 0, j = -1;
    nt[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i ++, j ++;
            nt[i] = j;
        }
        else j = nt[j];
    }
}

void kmp()
{
    int i = 0, j = 0;
    while (i < m)
    {
        if (j == -1 || t[i] == s[j])
        {
            stk[++ top] = i;
            match[i] = j;
            i ++, j ++;
        }
        else j = nt[j];
        
        if (j == n)
            top -= n, j = match[stk[top]] + 1;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s%s", t, s);
    n = strlen(s), m = strlen(t);
    getnext();
    kmp();

    for (int i = 1; i <= top; i ++ )
        putchar(t[stk[i]]);
    puts("");
    return 0;
}
