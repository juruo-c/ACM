#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;

int ans[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t --)
	{
		int n;
		scanf("%d", &n);
		ans[1] = 1;
		for (int i = n; i >= 2; i -= 2)
			ans[i] = i - 1, ans[i - 1] = i;
		printf("%d", ans[1]);
		for (int i = 2; i <= n; i ++ )
			printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}