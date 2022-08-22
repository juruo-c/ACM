#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m, p;
struct T
{
	int l, r;
	LL sum, alz, mlz;
}t[N << 2];
int a[N];

void push_up(int i)
{
	t[i].sum = (t[i << 1].sum + t[i << 1 | 1].sum) % p;
}

void push_down(int i)
{
	LL mlz = t[i].mlz, alz = t[i].alz;
	t[i << 1].mlz = t[i << 1].mlz * mlz % p;
	t[i << 1].alz = (t[i << 1].alz * mlz % p + alz) % p;
	t[i << 1 | 1].mlz = t[i << 1 | 1].mlz * mlz % p;
	t[i << 1 | 1].alz = (t[i << 1 | 1].alz * mlz % p + alz) % p;
	t[i << 1].sum = (t[i << 1].sum * mlz % p + alz * (t[i << 1].r - t[i << 1].l + 1) % p) % p;
	t[i << 1 | 1].sum = (t[i << 1 | 1].sum * mlz % p + alz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1) % p ) %p;
	t[i].mlz = 1, t[i].alz = 0;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	t[i].mlz = 1;
	if (l == r)
	{
		t[i].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update_add(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum = (t[i].sum + k * (t[i].r - t[i].l + 1) % p) % p;
		t[i].alz = (t[i].alz + k) % p;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update_add(i << 1, l, r, k);
	if (r > mid) update_add(i << 1 | 1, l, r, k);
	push_up(i);
}

void update_mul(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r)
	{
		t[i].sum = t[i].sum * k % p;
		t[i].alz = t[i].alz * k % p;
		t[i].mlz = t[i].mlz * k % p;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update_mul(i << 1, l, r, k);
	if (r > mid) update_mul(i << 1 | 1, l, r, k);
	push_up(i);
}

LL query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r)
		return t[i].sum;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	LL s = 0;
	if (l <= mid) s = (s + query(i << 1, l, r)) % p;
	if (r > mid) s = (s + query(i << 1 | 1, l, r)) % p;
	return s;
}

int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);

	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 3) printf("%lld\n", query(1, l, r));
		else
		{
			int c;
			scanf("%d", &c);
			if (op == 1) update_mul(1, l, r, c);
			else update_add(1, l, r, c);
		}
	}
	return 0;
}