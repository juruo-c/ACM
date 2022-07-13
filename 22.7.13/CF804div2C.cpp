#include <iostream>

using namespace std;

const int N = 100005, mod = 1000000007;

int n;
int a[N];
int p[N];

int main()
{
	int t;scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
			scanf("%d", &a[i]), p[a[i]] = i;
		int l = p[0], r = p[1];
		if (l > r) swap(l, r);

		int ans = 1;
		for (int i = 2; i < n; i ++ )
		{
			if (p[i] > l && p[i] < r)
				ans = 1LL * ans * (r - l + 1 - i) % mod;
			else
			{
				if (p[i] < l) l = p[i];
				else r = p[i];
			}  
		}

		printf("%d\n", ans);
	}
	return 0;
}