#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
char s[N], t[N];
int a[N], b[N];
int ac, bc;

int main()
{
	int T;scanf("%d", &T);
	while (T -- )
	{
		ac = bc = 0;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		if (s[1] != t[1] || s[n] != t[n])
		{
			puts("-1");
			continue;
		}

		for (int i = 1; i <= n; i ++ ) s[i] -= '0', t[i] -= '0';
		for (int i = 1; i < n; i ++ ) 
		{
			if (s[i] ^ s[i + 1]) a[++ ac] = i;
			if (t[i] ^ t[i + 1]) b[++ bc] = i;
		}

		if (ac != bc)
		{
			puts("-1");
			continue;
		}

		long long ans = 0;
		for (int i = 1; i <= bc; i ++ )
			ans += abs(a[i] - b[i]);
		printf("%lld\n", ans);

	}
	return 0;
}