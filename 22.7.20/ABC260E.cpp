#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 200005;

int n, m;
int cnt[N];
int a[N], b[N];
vector<int> pos[N];
int ans[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d%d", &a[i], &b[i]);
		pos[a[i]].push_back(i);
		pos[b[i]].push_back(i);
	}

	int remain = n;
	for (int l = 1, r = 1; l <= m; l ++)
	{
		while (r <= m && remain)
		{
			for (auto x : pos[r])
			{
				if (cnt[x] == 0) remain --;
				cnt[x] ++;
			}
			r ++;
		}

		if (remain) break;
		ans[r - l] ++, ans[m - l + 2] --;

		for (auto x : pos[l])
		{
			cnt[x] --;
			if (cnt[x] == 0) remain ++;
		}
	}

	for (int i = 1; i <= m; i ++ )
	{
		ans[i] += ans[i - 1];
		if (i > 1) printf(" ");
		printf("%d", ans[i]);
	}

	return 0;
}