#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;

int n;
int a[N], b[N];

int main()
{
	int t;scanf("%d", &t);
	while(t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
			scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		
		for (int i = n; i >= 2; i -= 2)
			if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);

		bool flag = true;
		for (int i = 1; i <= n; i ++ )
			if (a[i] != b[i])
			{
				flag = false;
				break;
			}

		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}