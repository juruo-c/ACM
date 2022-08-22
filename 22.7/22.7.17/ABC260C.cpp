#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int n, x, y;
LL f[15][2];

LL dfs(int n, int col)
{
	if (n == 1)
	{
		if (!col) return 1;
		return 0;
	}
	if (f[n][col] != -1) return f[n][col];
	LL ans = 0;
	if (col)
	{
		ans += dfs(n - 1, 1);
		ans += x * dfs(n, 0);
	}
	else 
	{
		ans += dfs(n - 1, 1);
		ans += y * dfs(n - 1, 0);
	}
	return f[n][col] = ans;
}

int main()
{
	memset(f, -1, sizeof f);
	cin >> n >> x >> y;
	cout << dfs(n, 1);
	return 0;
}