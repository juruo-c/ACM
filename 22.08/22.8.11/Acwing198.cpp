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
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
ULL ans, ansnum; //ans: 小于n的最大反素数，ansnum: 该反素数的因子数
ULL n;

void dfs(int depth, ULL tmp, ULL num, int up)
{
    if (depth >= 16 || tmp > n) return;
    if (num > ansnum)
    {
        ansnum = num;
        ans = tmp;
    }
    //如果存在一个数比当前的ans小且因子数相等，那么当前的ans不是反素数，要变小
    if (num == ansnum && ans > tmp) ans = tmp;
    for (int i = 1; i <= up; i ++ )
    {
        if (tmp * p[depth] > n) break;
        dfs(depth + 1, tmp *= p[depth], num * (i + 1), i);
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%llu", &n);
    dfs(0, 1, 1, 60);

    printf("%llu", ans);

    return 0;
}
