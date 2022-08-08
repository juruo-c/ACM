#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int a[N];
unordered_map<LL, int> cnt;
bool flag = true;

void dfs(LL x)
{
	if (!n || !flag) return;
	if (cnt[x]) 
	{
		n --;
		cnt[x] --;
		return;
	}
	if (x == 1)
	{
		flag = false;
		return ;
	}
	dfs(x / 2);
	dfs((x + 1) / 2);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t --)
	{
		flag = true;
		scanf("%d", &n);
		LL sum = 0;
		cnt.clear();
		for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), cnt[a[i]] ++, sum += a[i];
		dfs(sum);
		if (!n) puts("YES");
		else puts("NO");
	}
	return 0;
}