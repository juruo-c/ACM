#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 20005;

int n, m, k;
int fa[N];
bool f[N];
int siz[N];

int getf(int x)
{
	return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++ ) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= k; i ++ )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = getf(u), v = getf(v);
		if (u != v)
		{
			siz[v] += siz[u];
			fa[u] = v;
		}
	}

	vector<int> Vec;
	for (int i = 1; i <= n; i ++ )
		if (getf(i) == i) Vec.push_back(i);

	f[0] = true;
	for (auto vec : Vec)
		for (int j = n; j >= siz[vec]; j --)
			f[j] |= f[j - siz[vec]];

	int ans = 1000000, res = -1;
	for (int i = 0; i <= n; i ++ )
		if (f[i] && ans > abs(i - m))
			ans = abs(i - m), res = i;

	printf("%d\n", res);

	return 0;
}