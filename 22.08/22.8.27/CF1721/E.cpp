#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000005;

int n;
char s[N + 15];
char t[15];
int nt[N * 2];
int f[N][26];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s", s);
    n = strlen(s);

    int i = 0, j = -1;
    nt[0] = -1;
    while(i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i ++, j ++;
            if (s[i] != s[j]) nt[i] = j;
            else nt[i] = nt[j];
        }
        else j = nt[j];
    }

    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", t);
        int lent = strlen(t);
        for (int k = n; k < n + lent; k ++ )
            s[k] = t[k - n];
        s[n + lent] = '\0';

        int nn = n + lent;
        int oi = i, oj = j;
        while (i < nn)
        {
            if (j == -1 || s[i] == s[j])    
                i ++, j ++, nt[i] = j;
            else j = nt[j];
        }

        for (int k = n + 1; k <= nn; k ++ )
            printf("%d ", nt[k]);
        puts("");
        i = oi, j = oj;
    }
    return 0;
}
