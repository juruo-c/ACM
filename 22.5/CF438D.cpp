#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
int a[N];
struct T
{
	int l, r;
	LL sum, mx;
}t[N << 2];

void push_up(int i)
{
	t[i].sum = t[i << 1].sum + t[i << 1 | 1].sum;
	t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].sum = t[i].mx = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update_set(int i, int pos, int k)
{
	if (t[i].l == t[i].r) 
	{
		t[i].sum = 1LL * k * (t[i].r - t[i].l + 1);
		t[i].mx = k;
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) update_set(i << 1, pos, k);
	else update_set(i << 1 | 1, pos, k);
	push_up(i);
}

void update_mod(int i, int l, int r, int p)
{
	if (t[i].mx < p) return;
	if (t[i].l == t[i].r)
	{
		t[i].mx %= p;
		t[i].sum %= p;
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update_mod(i << 1, l, r, p);
	if (r > mid) update_mod(i << 1 | 1, l, r, p);
	push_up(i);
}

LL query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].sum;
	int mid = (t[i].l + t[i].r) >> 1;
	LL s = 0;
	if (l <= mid) s += query(i << 1, l, r);
	if (r > mid) s += query(i << 1 | 1, l, r);
	return s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &a[i]);

	build(1, 1, n);

	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r, k, x;
		scanf("%d", &op);
		if (op == 3)
		{
			scanf("%d%d", &k, &x);
			update_set(1, k, x);
		}
		else
		{
			scanf("%d%d", &l, &r);
			if (op == 1) printf("%lld\n", query(1, l, r));
			else {
				scanf("%d", &x);
				update_mod(1, l, r, x);
			}
		}			
	}
	return 0;
}