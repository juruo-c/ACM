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

const int N = 1000005, mod = 998244353;

int n, k;
int nt[N], ext[N];
char s[N];
int f[N];

void getnext(char* s)
{
    n = strlen(s);
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

// void qnxt(char *c)
// {
// 	int len = strlen(c);
// 	int p = 0, k = 1, l; //我们会在后面先逐位比较出 nxt[1] 的值，这里先设 k 为 1
// 	//如果 k = 0，p 就会锁定在 |c| 不会被更改，无法达成算法优化的效果啦
// 	nxt[0] = len; //以 c[0] 开始的后缀就是 c 本身，最长公共前缀自然为 |c|
// 	while(p + 1 < len && c[p] == c[p + 1]) p++;
// 	nxt[1] = p; //先逐位比较出 nxt[1] 的值
// 	for(int i = 2; i < len; i++)
// 	{
// 		p = k + nxt[k] - 1; //定义
// 		l = nxt[i - k]; //定义
// 		if(i + l <= p) nxt[i] = l; //如果灰方框小于初始的绿方框,直接确定 nxt[i] 的值
// 		else
// 		{
// 			int j = max(0, p - i + 1);
// 			while(i + j < len && c[i + j] == c[j]) j++; //否则进行逐位比较
// 			nxt[i] = j;
// 			k = i; //此时的 x + nxt[x] - 1 一定刷新了最大值，于是我们要重新赋值 k
// 		}
// 	}
// }

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%s", s);
        scanf("%d", &k);
        getnext(s);
        for (int i = 1; i <= n; i ++ )
            f[i] = 0;

        // for (int i = 0; i < n; i ++ )
        //     printf("nt[%d] = %d\n", i, nt[i]);

        for (int i = 1; i <= n; i ++ )
        {
            int x = nt[i - 1];
            if (i + k - 1 > x) continue;
            x = (x - i + 1) / k * k;
            x += k;
            if (2 * i + k - 2 <= n) f[2 * i + k - 2] ++;
            if (2 * i + x - 2 <= n) f[2 * i + x - 2] --;
        }

        for (int i = 1; i <= n; i ++ )
            f[i] = (f[i] + mod) % mod;

        int ans = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (i + k <= n) f[i + k] = (f[i] + f[i + k]) % mod;
            ans = 1LL * ans * (f[i] + 1) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
