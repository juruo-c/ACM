#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5005;

bool map[N][N];
int n, m, k;
struct Point
{
	int x, y;
	bool operator < (const Point& p) const
	{
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
}p[N];

bool judge(int x, int y)
{
	return x < 1 || x > n || y < 1 || y > m;
}

int calc(int x, int y, int dx, int dy)
{
	int sum = 1;
	while (true)
	{
		if (judge(x + dx, y + dy)) break;
		if (map[x + dx][y + dy])
		{
			sum ++;
			x += dx, y += dy;
		}
		else return 0;
	}
	return sum;
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		memset(map, false, sizeof map);
		for (int i = 1; i <= k; i ++ )
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			map[p[i].x][p[i].y] = true;		
		}
		sort(p + 1, p + 1 + k);
		int ans = 2;
		for (int i = 1; i <= k; i ++ )
			for (int j = i + 1; j <= k; j ++ )
			{
				int dx = p[j].x - p[i].x, dy = p[j].y - p[i].y;
				if (p[j].x + (ans - 2) * dx > n) break;
				if (p[j].y + (ans - 2) * dy > m || p[j].y + (ans - 2) * dy < 1) continue;
				if (!judge(p[i].x - dx, p[i].y - dy)) continue;
				ans = max(ans, calc(p[i].x, p[i].y, dx, dy));
			}

		if (ans < 3) puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}