#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200005;

struct Seq
{
	LL l, r;
	bool operator < (const Seq& b) const
	{
		return l < b.l;
	}
}a[N];

int main()
{
	int n;
	scanf("%d", &n);
	LL mi = 1e18, mx = -1e18;
	for (int i = 1; i <= n; i ++ )
	{
		LL x, r;
		scanf("%lld%lld", &x, &r);
		a[i].l = x - r, a[i].r = x + r;
		mi = min(a[i].l, mi);
		mx = max(a[i].r, mx);
	}
	sort(a + 1, a + 1 + n);
	LL res = 0;
	LL l = -1e18, r = -1e18;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i].l > r)
		{
			res += r - l;
			l = a[i].l;
			r = a[i].r;
		}
		else
		{
			r = max(r, a[i].r);
		}
	}
	res += r - l;
	printf("%lld\n", mx - mi - res);
	return 0;
}