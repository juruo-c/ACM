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
				if (judge(p[i].x - dx, p[i].y - dy)) continue;
			}
	}
	return 0;
}