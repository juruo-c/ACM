#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

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
		int n, k;
		scanf("%d%d", &n, &k);
		if (k % 2) 
		{
			puts("YES");
			for (int i = 1; i <= n; i += 2)
				printf("%d %d\n", i, i + 1);
			continue;
		}
		if (k / 2 % 2 == 0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int j = 1;
		for (int i = 2; i <= n; i += 2 )
			if (i % 4 == 0)
			{
				printf("%d %d\n", j, i);
				j += 2;
			}
		for (int i = 2; i <= n; i += 2)
			if (i % 4)
			{
				printf("%d %d\n", i, j);
				j += 2;
			}
	}
	return 0;
}