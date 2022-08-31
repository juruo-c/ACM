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

const int N = 20000005;

char s[N], t[N];
int ext[N], nt[N];

void getnext(char* s)
{
    // nt[i]: s[i:n]与s[1:n]的最长公共前缀长度
    int n = strlen(s);
    int p = 0, k = 1, l;
    nt[0] = n;
    while (p + 1 < n && s[p] == s[p + 1]) p++;
    nt[1] = p;
    for (int i = 2; i < n; i ++ )
    {
        p = k + nt[k] - 1;
        l = nt[i - k];
        if (i + l <= p) nt[i] = l;
        else 
        {
            int j = max(0, p - i + 1);
            while (i + j < n && s[i + j] == s[j]) j ++ ;
            nt[i] = j;
            k = i;
        }
    }
}

void exkmp(char* s, char* t)
{
    // ext[i]: s[i:n]与t[1:n]的最长公共前缀长度
    int n = strlen(s), m = strlen(t);
    int p = 0, k = 0, l;
    while (p < n && p < m && s[p] == t[p]) p ++;
    ext[0] = p;
    for (int i = 1; i < n; i ++ )
    {
        p = k + ext[k] - 1;
        l = nt[i - k];
        if (i + l <= p) ext[i] = l;
        else 
        {
            int j = max(0, p - i + 1);
            while (i + j < n && j < m && s[i + j] == t[j]) j ++;
            ext[i] = j;
            k = i; 
        }
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s%s", s, t);
    getnext(t);
    exkmp(s, t);
    int n = strlen(t);
    int m = strlen(s);
    LL z = 0;
    for (int i = 0; i < n; i ++ )
        z ^= 1LL * (i + 1) * (nt[i] + 1);
    LL a = 0;
    for (int i = 0; i < m; i ++ )
        a ^= 1LL * (i + 1) * (ext[i] + 1);
    
    printf("%lld\n%lld\n", z, a);

    return 0;
}
