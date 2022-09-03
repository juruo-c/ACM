#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100005;

int n, m, V;
int c[N], d[N];
int fa[N];
int f[N];

int getf(int x)
{
	if (x == fa[x]) return x;
	int t = fa[x];
	fa[x] = getf(fa[x]);
	return fa[x];
}

int main()
{
	scanf("%d%d%d", &n, &m, &V);
	for (int i = 1; i <= n; i ++ ) scanf("%d%d", &c[i], &d[i]), fa[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = getf(u), v = getf(v);
		// cout << "fa: " << u << " " << v << endl;
		if (u != v)
		{
			// cout << "fa: " << u << " " << v << endl;
			fa[v] = u;
			c[u] += c[v], d[u] += d[v];
		}
	}

	vector<int> Vec;
	for (int i = 1; i <= n; i ++ )
		if (getf(i) == i)
			Vec.push_back(i);

	// for (auto v : Vec) printf("%d %d\n", c[v], d[v]);
	
	for (auto v : Vec)
	{
		for (int i = V; i >= c[v]; i -- )
			f[i] = max(f[i], f[i - c[v]] + d[v]);
	}

	printf("%d\n", f[V]);

	return 0;
}