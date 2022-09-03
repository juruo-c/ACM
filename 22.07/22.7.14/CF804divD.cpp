#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5005;

int n;
int a[N];
int cnt[N];
bool de[N][N];
int f[N];

int main()
{
	int t;scanf("%d", &t);
	while (t -- )
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

		for (int i = 1; i <= n + 1; i ++ )
			for (int j = 0; j <= n; j ++ )
				de[i][j] = false;
		for (int i = 1; i <= n + 1; i ++ )
			de[i][i - 1] = true;
		for (int i = 1; i <= n; i ++ )
		{
			int mx = 0;
			for (int j = 1; j <= n; j ++ ) cnt[j] = 0;
			cnt[a[i]] ++;
			mx = 1;
			for (int j = i + 1; j <= n; j ++ )
			{
				int len = j - i + 1;
				cnt[a[j]] ++;
				mx = max(mx, cnt[a[j]]);
				if (len % 2 || mx > len / 2) de[i][j] = false;
				else de[i][j] = true;
			}
		}

		for (int i = 1; i <= n; i ++ ) f[i] = 0;
		for (int i = 1; i <= n; i ++ )
			if (de[1][i - 1]) f[i] = 1;
 		
 		for (int i = 1; i <= n; i ++ )
 			for (int j = 1; j < i; j ++ )
 			{
 				if ((!f[j]) || a[i] != a[j] || (!de[j + 1][i - 1])) continue;
 				f[i] = max(f[i], f[j] + 1);
 			}

 		int ans = 0;
 		for (int i = 1; i <= n; i ++ )
 			if (de[i + 1][n]) ans = max(ans, f[i]);

 		printf("%d\n", ans);

	}
	return 0;
}