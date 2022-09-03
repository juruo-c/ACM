#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 200005;

int n;
unordered_set<int> from[N], to[N];
int fa[N], siz[N];
bool vis[N];

int getf(int x)
{
	return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

void merge(int u, int v)
{
	u = getf(u), v = getf(v);
	if (u == v) return;
	if (to[u].size() < to[v].size()) swap(u, v);
	fa[v] = u;
	siz[u] += siz[v];
	vector<pair<int, int> > M;

	for (auto p : to[v])
	{
		from[p].erase(v);
		to[u].insert(p);
		from[p].insert(u);
		if (!vis[p] && from[p].size() == 1)
			vis[p] = true, M.push_back({p, *from[p].begin()});
	}

	for (auto t : M)
		merge(t.first, t.second);

}

int main()
{
	int t;scanf("%d", &t);
	int kase = 0;
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) fa[i] = i, siz[i] = 1, vis[i] = false, from[i].clear(), to[i].clear();
		for (int i = 1; i <= n; i ++ )
		{
			int ki;scanf("%d", &ki);
			for (int j = 0; j < ki; j ++ )
			{
				int u;scanf("%d", &u);
				from[i].insert(u);
				to[u].insert(i);
			}
		}

		for (int i = 1; i <= n; i ++ )
			if (from[i].size() == 1)
				vis[i] = true, merge(*from[i].begin(), i);

		int ans = 0;
		for (int i = 1; i <= n; i ++ )
			ans = max(ans, siz[getf(i)]);

		printf("Case #%d: %d\n", ++kase, ans);

	}
	return 0;
}