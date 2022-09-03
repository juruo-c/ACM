#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 300005, mod = 1000000009;

int n, m;
int a[N];
int s[N], f[N];
struct T
{
	int l, r;
	int sum;
	int a1, a2;
}t[N << 2];

int h(int a1, int a2, int i)
{
	if(i == 1) return a1;
	if(i == 2) return a2;
	return (1LL * a1 * f[i - 2] + 1LL * a2 * f[i - 1]) % mod;
}

int sum(int a1, int a2, int i)
{
	// sum(i) = f(i + 2) - f(2)
	if (i == 1) return a1;
	if (i == 2) return (a1 + a2) % mod;
	return (h(a1, a2, i + 2) - a2 + mod) % mod;
}

void push_up(int i)
{
	t[i].sum = (t[i << 1].sum + t[i << 1 | 1].sum) % mod;
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void push_down(int i)
{
	if (t[i].a1)
	{
		int mid = (t[i].l + t[i].r) >> 1;
		t[i << 1].a1 = (t[i << 1].a1 + t[i].a1) % mod;
		t[i << 1].a2 = (t[i << 1].a2 + t[i].a2) % mod;
		t[i << 1].sum = (t[i << 1].sum + sum(t[i].a1, t[i].a2, mid - t[i].l + 1)) % mod;
		int a1 = h(t[i].a1, t[i].a2, mid - t[i].l + 2), a2 = h(t[i].a1, t[i].a2, mid - t[i].l + 3);
		t[i << 1 | 1].a1 = (t[i << 1 | 1].a1 + a1) % mod;
		t[i << 1 | 1].a2 = (t[i << 1 | 1].a2 + a2) % mod;
		t[i << 1 | 1].sum = (t[i << 1 | 1].sum + sum(a1, a2, t[i].r - mid)) % mod;
		t[i].a1 = t[i].a2 = 0;
	}
}

void update(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) 
	{
		t[i].a1 = (t[i].a1 + f[t[i].l - l + 1]) % mod;
		t[i].a2 = (t[i].a2 + f[t[i].l - l + 2]) % mod;
		t[i].sum = (t[i].sum + sum(f[t[i].l - l + 1], f[t[i].l - l + 2], t[i].r - t[i].l + 1)) % mod;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r);
	if (r > mid) update(i << 1 | 1, l, r);
	push_up(i);
}

int query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i].sum;
	push_down(i);
	int s = 0;
	int mid = (t[i].l + t[i].r )>> 1;
	if (l <= mid) s = (s + query(i << 1, l, r)) % mod;
	if (r > mid) s = (s + query(i << 1 | 1, l, r)) % mod;
	return s;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n; i ++ )
		scanf("%d", &a[i]), s[i] = (s[i - 1] + a[i]) % mod;
	f[1] = f[2] = 1;
	for (int i = 3; i <= n + 2; i ++ ) f[i] = (f[i - 1] + f[i - 2]) % mod;

	build(1, 1, n);
	for (int i = 1; i <= m; i ++ )
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) update(1, l, r);
		else printf("%d\n", (query(1, l, r) + (s[r] - s[l - 1] + mod) % mod) % mod);
	}

	return 0;
}