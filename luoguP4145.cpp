#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
LL a[N];
struct T
{
	int l, r;
	LL mx, sum;
}t[N << 2];

void push_up(int i)
{
	t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].mx = t[i].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int l, int r)
{
	if (t[i].mx == 1) return;
	if (t[i].l == t[i].r) 
	{
		t[i].mx = t[i].sum = sqrt(t[i].sum);
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r);
	if (r > mid) update(i << 1 | 1, l, r);
	push_up(i);
}

LL query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	int mid = (t[i].l + t[i].r) >> 1;
	LL s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

int main()
{
	freopen("P4145_6.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
		scanf("%lld", &a[i]);
	scanf("%d", &m);
	build(1, 1, n);
	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (l > r) swap(l, r);
		if (!op) update(1, l, r);
		else printf("%lld\n", query(1, l, r));
	}
	return 0;
}