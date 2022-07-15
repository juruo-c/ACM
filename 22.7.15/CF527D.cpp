#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
struct C
{
	int x, w;
	bool operator < (const C& b) const
	{
		return x < b.x;
	}
}c[N];
struct P
{
	int l, r;
	bool operator < (const P& b) const
	{
		return r < b.r;
	}
}p[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
		scanf("%d%d", &c[i].x, &c[i].w);
	sort(c + 1, c + 1 + n);

	for (int i = 1; i <= n; i ++ )
		p[i].l = c[i].x - c[i].w, p[i].r = c[i].x + c[i].w;
	sort(p + 1, p + 1 + n);

	int s = -2e9, ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (p[i].l >= s)
		{
			s = p[i].r;
			ans ++;
		}
	}

	printf("%d\n", ans);

	return 0;
}