#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50005;

int n, m;
struct T
{
	int l, r;
	int mx, lmx, rmx;
	int lz;
}t[N << 2];

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	t[i].mx = t[i].lmx = t[i].rmx = r - l + 1;
	t[i].lz = -1;
	if (l == r)
		return ;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
}

void push_down(int i)
{
	if (t[i].lz != -1)
	{
		int lz = t[i].lz;
		t[i << 1].lz = t[i << 1 | 1].lz = lz;
		t[i << 1].mx = t[i << 1].lmx = t[i << 1].rmx = lz * (t[i << 1].r - t[i << 1].l + 1);
		t[i << 1 | 1].mx = t[i << 1 | 1].lmx = t[i << 1 | 1].rmx = lz * (t[i << 1 | 1].r - t[i << 1 | 1].l + 1);
		t[i].lz = -1;
	}
}

void push_up(int i)
{
	t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
	t[i].lmx = t[i << 1].lmx;
	t[i].rmx = t[i << 1 | 1].rmx;
	if (t[i << 1].lmx == t[i << 1].r - t[i << 1].l + 1) 
		t[i].lmx = t[i].lmx + t[i << 1 | 1].lmx;
	if (t[i << 1 | 1].rmx == t[i << 1 | 1].r - t[i << 1 | 1].l + 1) 
		t[i].rmx = t[i].rmx + t[i << 1].rmx;
	t[i].mx = max(t[i << 1].rmx + t[i << 1 | 1].lmx, t[i].mx);
}

void update(int i, int l, int r, int k)
{
	if (l <= t[i].l && t[i].r <= r) 
	{
		t[i].mx = t[i].lmx = t[i].rmx = k * (t[i].r - t[i].l + 1);
		t[i].lz = k;
		return;
	}
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k);
	if (r > mid) update(i << 1 | 1, l, r, k);
	push_up(i);
}

int query(int i, int x)
{
	if (t[i].l == t[i].r) return t[i].l;
	push_down(i);
	int mid = (t[i].l + t[i].r) >> 1;
	if (t[i << 1].mx >= x) return query(i << 1, x);
	if (t[i << 1].rmx + t[i << 1 | 1].lmx >= x) return mid - t[i << 1].rmx + 1;
	return query(i << 1 | 1, x);
}

int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 1; i <= m; i ++ )
	{
		int op, x, y;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &x);
			
			if (t[1].mx >= x)
			{	
				int t = query(1, x);
				printf("%d\n", t);
				update(1, t, t + x - 1, 0);
			}
			else puts("0");
		}
		else
		{
			scanf("%d%d", &x, &y);
			update(1, x, x + y - 1, 1);
		}
	}
	return 0;
}