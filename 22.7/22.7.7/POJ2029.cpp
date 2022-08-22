#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int n, w, h;
int a[N][N];
int s, t;

int main()
{
	while (~scanf("%d", &n) && n)
	{
		scanf("%d%d", &w, &h);
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i ++ )
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		scanf("%d%d", &s, &t);

		for (int i = 1; i <= w; i ++ )
			for (int j = 1; j <= h; j ++ )
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

		int ans = 0;
		for (int i = 1; i + s - 1 <= w; i ++ )
			for (int j = 1; j + t - 1 <= h; j ++ )
			{
				int x = i + s - 1, y = j + t - 1;
				ans = max(ans, a[x][y] - a[i - 1][y] - a[x][j - 1] + a[i - 1][j - 1]);
			}

		printf("%d\n", ans);
	}
	return 0;
}