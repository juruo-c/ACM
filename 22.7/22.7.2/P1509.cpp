#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int n, m, r;
int g[N][N];
int f[N][N];
int rmb[N], rp[N], Time[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
		scanf("%d%d%d", &rmb[i], &rp[i], &Time[i]);

	scanf("%d%d", &m, &r);
	for (int i = 1; i <= n; i ++ )
		for (int j = m; j >= rmb[i]; j -- )
			for (int k = r; k >= rp[i]; k -- )
				if (g[j][k] < g[j - rmb[i]][k - rp[i]] + 1)
				{
					f[j][k] = f[j - rmb[i]][k - rp[i]] + Time[i];
					g[j][k] = g[j - rmb[i]][k - rp[i]] + 1;
				}
				else if(g[j][k] == g[j - rmb[i]][k - rp[i]] + 1 && f[j][k] > f[j - rmb[i]][k - rp[i]] + Time[i])
				{
					f[j][k] = f[j - rmb[i]][k - rp[i]] + Time[i];
				}
	
	printf("%d\n", f[m][r]);
	return 0;
}