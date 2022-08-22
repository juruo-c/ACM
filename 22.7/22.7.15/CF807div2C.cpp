#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, c, q;
char s[N];
struct Seq
{
	LL l, r;
}seq[50];
LL sum[50];

int main()
{
	int t;
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%d%d%d", &n, &c, &q);
		scanf("%s", s + 1);
		sum[0] = n;
		for (int i = 1; i <= c; i ++ )
			scanf("%lld%lld", &seq[i].l, &seq[i].r), sum[i] = sum[i - 1] + seq[i].r - seq[i].l + 1;

		for (int i = 1; i <= q; i ++ )
		{
			LL x;
			scanf("%lld", &x);
			while (x > n)
			{
				int p;
				for (p = 1; p <= c; p ++ )
					if (sum[p] >= x) break;
				x = x - sum[p - 1] + seq[p].l - 1;
			}
			printf("%c\n", s[x]);
		}

	}
	return 0;
}