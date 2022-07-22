#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n, m, q;
int a[N];

struct T
{
	int l, r;
	int mx;
}t[N << 2];

void push_up(int i)
{
	t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r) 
	{
		t[i].mx = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].mx;
	int mid = (t[i].l + t[i].r) >> 1;
	int s = 0;
	if (l <= mid) s = max(s, query(i << 1, l, r));
	if (r > mid) s = max(s, query(i << 1 | 1, l, r));
	return s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++ )
		scanf("%d", &a[i]);

	build(1, 1, m);

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		int xs, ys, xf, yf, k;
		scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);

		if (ys > yf) swap(ys, yf);

		int mx = query(1, ys, yf);
		if (mx >= n || (yf - ys) % k) 
		{
			puts("NO");
			continue;
		}

		if (mx < xs)
		{
			if (abs(xs - xf) % k) puts("NO");
			else puts("YES");
		}
		else
		{
			int t = ((mx - xs) / k + 1) * k;
			if (xs + t > n) puts("NO");
			else
			{
				if (abs(xs - xf) % k) puts("NO");
				else puts("YES");
			}
		}

	}

	return 0;
}