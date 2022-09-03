#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10005;

int n;
int cnt[10];
bool f[10][N];
vector<int> nt[N];

int calc(int x)
{
	int res = 0;
	for (int j = 0; j < 10; j ++ )
		if ((x & (1 << j)) == 0)
			res += cnt[j];
	return res;
}

bool check(int mx)
{
	memset(f, false, sizeof f);
	f[0][0] = true;
	for (int i = 0; i < 5; i ++ )
		for (int j = 0; j < 1 << 10; j ++ )
		{
			if (!f[i][j]) continue;
			for (int k = 0; k < nt[j].size(); k ++ )
			{
				int t = nt[j][k];
				if (calc(t ^ j) <= mx)
					f[i + 1][t] = true;
			}
		}	
	for (int i = 0; i < 1 << 10; i ++ )
		if (f[5][i]) return true;
	return false;
}

int main()
{
	for (int i = 0; i < (1 << 10); i ++ )
		for (int j = 1; j < (1 << 10); j ++ )
		{
			if (i & j) continue;
			nt[i].push_back(i | j);
		}
	int t;scanf("%d", &t);
	while (t -- )
	{
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
		{
			int x;scanf("%d", &x);
			cnt[x % 10] ++;
		}

		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}

		printf("%d\n", r);

	}
	return 0;
}