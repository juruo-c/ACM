#include <iostream>
#include <cstdio>

using namespace std;

const int N = 105;

int a[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i ++ )
			scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 1; i <= k; i ++ )
			if (a[i] > k) ans ++;
		printf("%d\n", ans);
	}
	return 0;
}