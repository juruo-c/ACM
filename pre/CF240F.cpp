#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100005;

int n, m;
char s[N];
struct T
{
	int l, r;
	int sum, lz;
}t[26][N << 2];
int cnt[26];

void push_up(int i, int k)
{
	t[k][i].sum = (t[k][i << 1].sum + t[k][i << 1 | 1].sum);
}

void build(int i, int l, int r, int k)
{
	t[k][i].l = l, t[k][i].r = r;
	t[k][i].lz = -1;
	if (l == r)
	{
		t[k][i].sum = ((s[l] - 'a') == k); 
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid, k);
	build(i << 1 | 1, mid + 1, r, k);
	push_up(i, k);
}

void push_down(int i, int k)
{
	if (t[k][i].lz != -1)
	{
		int lz = t[k][i].lz;
		t[k][i << 1].lz = lz;
		t[k][i << 1 | 1].lz = lz;
		t[k][i << 1].sum = lz * (t[k][i << 1].r - t[k][i << 1].l + 1);
		t[k][i << 1 | 1].sum = lz * (t[k][i << 1 | 1].r - t[k][i << 1 | 1].l + 1);
		t[k][i].lz = -1;
	}
}

int query(int i, int l, int r, int k)
{
	if (l <= t[k][i].l && t[k][i].r <= r)
		return t[k][i].sum;
	push_down(i, k);
	int mid = (t[k][i].l + t[k][i].r) >> 1;
	int s = 0;
	if (l <= mid) s += query(i << 1, l, r, k);
	if (r > mid) s += query(i << 1 | 1, l, r, k);
	return s;
}

void update(int i, int l, int r, int k, int val)
{
	if (l <= t[k][i].l && t[k][i].r <= r)
	{
		t[k][i].lz = val;
		t[k][i].sum = val * (t[k][i].r - t[k][i].l + 1);
		return;
	}
	push_down(i, k);
	int mid = (t[k][i].l + t[k][i].r) >> 1;
	if (l <= mid) update(i << 1, l, r, k, val);
	if (r > mid) update(i << 1 | 1, l, r, k, val);
	push_up(i, k);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 0; i < 26; i ++ )
		build(1, 1, n, i);

	for (int i = 1; i <= m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		for (int j = 0; j < 26; j ++ )
			cnt[j] = query(1, l, r, j);

		int c = 0, id = -1;
		for (int j = 0; j < 26; j ++ )
			if ( cnt[j] % 2 ) c ++, id = j;
		if ( c >= 2 ) continue;

		for (int j = 0; j < 26; j ++ ) update(1, l, r, j, 0);

		int L = l, R = r;
		if (c)
		{
			cnt[id] --;
			int mid = l + r >> 1;
			update(1, mid, mid, id, 1);
		}
		for (int j = 0; j < 26; j ++ )
			if (cnt[j])
			{
				int num = cnt[j] / 2;
				update(1, L, L + num - 1, j, 1);
				update(1, R - num + 1, R, j, 1);
				L += num;
				R -= num;
			}

	}

	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 0; j < 26; j ++ )
			if (query(1, i, i, j)) 
			{
				s[i] = 'a' + j;
				break;
			}
	}

	printf("%s", s + 1);
	return 0;
}