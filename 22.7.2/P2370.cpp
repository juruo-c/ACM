#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1005;

int n, p, S;
int w[N], v[N];
int f[N];
int g[N];

bool dp(int x)
{
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i ++ )
	{
		if (w[i] > x) continue;
		for (int j = S; j >= w[i]; j -- )
		{
			f[j] = max(f[j], f[j - w[i]] + v[i]);
			if (f[j] >= p) return true;
		}
	}

	return false;
}

int main()
{
	// freopen("1.in", "r", stdin);
	scanf("%d%d%d", &n, &p, &S);
	for (int i = 1; i <= n; i ++ ) scanf("%d%d", &w[i], &v[i]);
	
	int l = 1, r = S;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (dp(mid)) r = mid;
		else l = mid + 1; 
	}

	if (dp(l)) printf("%d\n", l);
	else puts("No Solution!");

	return 0;
}