#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <deque>

using namespace std;

typedef pair<int, int> PII;

const int N = 100005;

int a[N];
struct Query
{
	int num, id, k;
	bool operator < (const Query& q) const
	{
		return k < q.k;
	}
}ask[N];
int ans[N];
int cnt[N];

void complete(deque<PII>& que)
{
	auto t1 = que.front();
	que.pop_front();
	auto t2 = que.front();
	que.pop_front();
	if (t1.first < t2.first) 
	{
		cnt[t2.second] ++;
		que.push_front(t2);
		que.push_back(t1);
	}
	else 
	{
		cnt[t1.second] ++;
		que.push_front(t1);
		que.push_back(t2);
	}
}

int main()
{
	#ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i ++ ) cnt[i] = 0;
		deque<PII> que;
		int pos;
		for (int i = 1; i <= n; i ++ ) 
		{
			scanf("%d", &a[i]), que.push_back({a[i], i});
			if (a[i] == n) pos = i;
		}
		for (int i = 1; i <= q; i ++ ) scanf("%d%d", &ask[i].id, &ask[i].k), ask[i].num = i;
		sort(ask + 1, ask + 1 + q);

		int cur = 0;
		int i = 1;
		while (i <= q)
		{
			if (ask[i].k > n) break;
			while (cur < ask[i].k)
			{
				complete(que);
				cur ++;
			}
			ans[ask[i].num] = cnt[ask[i].id];
			i ++;
			while (i <= q && ask[i].k == ask[i - 1].k)
			{
				ans[ask[i].num] = cnt[ask[i].id];
				i ++;
			}
		}

		while (cur < n)
		{
			complete(que);
			cur ++;
		}

		while (i <= q)
		{
			ans[ask[i].num] = cnt[ask[i].id];
			if (ask[i].id == pos) ans[ask[i].num] += ask[i].k - n;
			i ++;
		}		
		for (int i = 1; i <= q; i ++ ) printf("%d\n", ans[i]);
	}
	return 0;
}