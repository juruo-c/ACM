#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10005;
const double eps = 1e-9;

int n;
struct edge
{
	int to, next;
}E[N << 1];
int head[N], cnt;
double k[N], e[N];
double A[N], B[N], C[N];
int d[N];

void add(int u, int v)
{
	E[++ cnt] = {v, head[u]};
	head[u] = cnt;
}

bool dfs(int u, int ff)
{
	A[u] = k[u];
	B[u] = (1 - k[u] - e[u]) / d[u];
	C[u] = (1 - k[u] - e[u]);
	double t = 0;
	for (int i = head[u]; i; i = E[i].next)
	{
		int v = E[i].to;
		if (v == ff) continue;
		if (!dfs(v, u)) return false;
		A[u] += (1 - k[u] - e[u]) / d[u] * A[v];
		C[u] += (1 - k[u] - e[u]) / d[u] * C[v];
		t += (1 - k[u] - e[u]) / d[u] * B[v];
	}
	if (fabs(1 - t) < eps) return false;
	A[u] /= (1 - t);
	B[u] /= (1 - t);
	C[u] /= (1 - t);
	return true;
}

int main()
{
	int t, kase = 0;
	scanf("%d", &t);
	while (t --)
	{
		cnt = 0;
		memset(d, 0, sizeof d);
		memset(head, 0, sizeof head);
		scanf("%d", &n);
		for (int i = 1; i < n; i ++ )
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
			d[u] ++, d[v] ++;
		}
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%lf%lf", &k[i], &e[i]);
			k[i] /= 100, e[i] /= 100;
		}

		printf("Case %d: ", ++ kase);
		bool flag = dfs(1, 0);
		if (flag && fabs(1 - A[1]) > eps) printf("%.6f\n", C[1] / (1 - A[1]));
		else printf("impossible\n");
	}
	return 0;
}