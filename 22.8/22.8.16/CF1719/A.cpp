#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define ZYCMH 1

using namespace std;

const int N = 100005;

int main()
{
	#ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int t = n + m - 2;
		if (t % 2) puts("Burenka");
		else puts("Tonya");
	}
	return 0;
}