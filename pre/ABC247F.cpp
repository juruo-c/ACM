#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 200005, mod = 998244353;

int n;
int f[N];
int fa[N], siz[N];
int p[N], q[N];

int getf(int x)
{
	return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i ++ )
		scanf("%d", &q[i]);
	for (int i = 1; i <= n; i ++ )
		fa[i] = i, siz[i] = 1;

	f[1] = 1, f[2] = 3;
	for (int i = 3; i <= n; i ++ ) f[i] = (f[i - 1] + f[i - 2]) % mod;
	
	for (int i = 1; i <= n; i ++ )
	{
		int fp = getf(p[i]);
		int fq = getf(q[i]);
		if (fp != fq)
		{
			fa[fp] = fq;
			siz[fq] += siz[fp];
		}
	}

	set<int> rt;
	for (int i = 1; i <= n; i ++ ) rt.insert(getf(i));

	int ans = 1;
	for (auto x : rt)
	{
		ans = 1LL * ans * f[siz[x]] % mod;
	}

	printf("%d\n", ans);

	return 0;
}