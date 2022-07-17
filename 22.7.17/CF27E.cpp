#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

ULL p[] = {2, 3, 5, 7, 11, 13, 17, 19,
		23, 29, 31, 37, 41, 43, 47, 53};

ULL ans;
ULL n;

//depth: 当前枚举到第几个素数
//val: 当前因子数量为num时数的数值
//num: 当前因子数
//up: 上一个素数的幂次
void dfs(ULL depth, ULL val, ULL num, ULL up)
{
	if (num > n || depth >= 16) return;
	if (num == n && ans > val)
	{
		ans = val;
		return;
	}
	for (int i = 1; i <= up; i ++ )
	{
		if (val * p[depth] > ans) break;
		dfs(depth + 1, val = val * p[depth], num * (i + 1), i);
	}
}

int main()
{
	scanf("%llu", &n);
	ans = ~(ULL)0;
	dfs(0, 1, 1, 64);
	printf("%llu", ans);
	return 0;
}