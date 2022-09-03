#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

int n, m, x;
struct T
{
	LL cnt;
	int l, r;
	vector<PII> pre, suf;
}t[N << 2];
int a[N];

T merge(T a, T b)
{
	if (!a.pre.size()) return b;
	if (!b.pre.size()) return a;
	
	T res;
	res.l = a.l, res.r = b.r;
	res.cnt = a.cnt + b.cnt;
	for (auto i : a.suf)
		for (auto j : b.pre)
			if ((i.first | j.first) >= x)
				res.cnt += 1LL * i.second * j.second;

	res.pre = a.pre;
	LL num = a.pre.back().first;
	for (auto i : b.pre)
	{
		if ((i.first | num) == num) res.pre.back().second += i.second;
		else
		{
			res.pre.push_back({i.first | num, i.second});
			num |= i.first;
		}
	}

	res.suf = b.suf;
	num = b.suf.back().first;
	for (auto i : a.suf)
	{
		if ((i.first | num) == num) res.suf.back().second += i.second;
		else{
			res.suf.push_back({i.first | num, i.second});
			num |= i.first;
		}
	}

	return res;
}

void push_up(int i)
{
	t[i] = merge(t[i << 1], t[i << 1 | 1]);
}

void build(int i, int l, int r)
{
	t[i].l = l, t[i].r = r;
	if (l == r)
	{
		t[i].pre.push_back({a[l], 1});
		t[i].suf.push_back({a[l], 1});
		t[i].cnt = (a[l] >= x);
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	push_up(i);
}

void update(int i, int pos, int k)
{
	if (t[i].l == t[i].r)
	{
		t[i].pre.back().first = k;
		t[i].suf.back().first = k;
		t[i].cnt = (k >= x);
		return;
	}
	int mid = (t[i].l + t[i].r) >> 1;
	if (pos <= mid) update(i << 1, pos, k);
	else update(i << 1 | 1, pos, k);
	push_up(i);
}

T query(int i, int l, int r)
{
	if (l <= t[i].l && t[i].r <= r) return t[i];
	int mid = (t[i].l + t[i].r) >> 1;
	if (l > mid) return query(i << 1 | 1, l, r);
	else if (r <= mid) return query(i << 1, l, r);
	else return merge(query(i << 1, l, r), query(i << 1 | 1, l, r));
}

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	build(1, 1, n);
	
	for (int i = 1; i <= m; i ++ )
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int pos, k;
			scanf("%d%d", &pos, &k);
			update(1, pos, k);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r).cnt);
		}
	}
	return 0;
}
