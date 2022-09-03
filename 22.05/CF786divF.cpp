#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;

int n, m, q;
int c[N][N];
char s[N][N];
int a[N][N];

void update(int i, int x, int k)
{
	for (int j = x; j <= (i ? n : m); j += (j & -j))
		c[i][j] += k;
}

int query(int i, int x)
{
	int res = 0;
	for (int j = x; j; j -= (j & -j))
		res += c[i][j];
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i ++ )
		scanf("%s", s[i] + 1);

	int cnt = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			if (s[i][j] == '*') a[i][j] = 1, cnt ++;

	for (int j = 1; j <= m; j ++ )
		for (int i = 1; i <= n; i ++ )
			if (a[i][j])
				update(j, i, 1);

	for (int i = 1; i <= m; i ++ )
		update(0, i, query(i, n));

	for (int i = 1; i <= q; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (a[x][y])
		{
			update(y, x, -1);
			update(0, y, -1);
			cnt --;
			a[x][y] = 0;
		}
		else 
		{
			update(y, x, 1);
			update(0, y, 1);
			a[x][y] = 1;
			cnt ++;
		}


		int col = cnt / n;
		int lastcol = cnt % n;
		int ans = col * n - query(0, col);
		if (lastcol)
		{
			ans += lastcol - query(col + 1, lastcol);
		}
		printf("%d\n", ans);
	}

	return 0;
}