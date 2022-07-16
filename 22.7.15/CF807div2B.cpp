#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int a[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		int p = 0;
		LL ans = 0;
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d", &a[i]);
			if (a[i] && !p) p = i;
		}
		if (p == n || !p) puts("0");
		else
		{
			for (int i = p; i <= n - 1; i ++ )
				if (a[i]) ans += a[i];
				else ans ++;
			printf("%lld\n", ans);
		} 
	}
	return 0;
}