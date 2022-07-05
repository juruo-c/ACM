#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 500005;

int n;
char s[N];
int fa[N];
struct Edge
{
	int to, next;
}e[N << 1];
int head[N], cnt;
LL f[N], last[N], g[N];

void add(int u, int v)
{
	e[++ cnt] = {v, head[u]};
	head[u] = cnt;
}



int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 2; i <= n; i ++ )
		scanf("%d", &fa[i]);

	for (int i = 1; i <= n; i ++ )
	{
		if (s[i] == '(')
		{
			last[i] = i;
			f[i] = f[fa[i]];
		}
		else
		{
			if (last[fa[i]])
			{
				last[i] = last[fa[last[fa[i]]]];
				g[i] = g[fa[last[fa[i]]]] + 1;
				f[i] = f[fa[i]] + g[i];
			}	
			else
			{
				last[i] = last[fa[i]];
				f[i] = f[fa[i]];
			}
		}
	}

	// for (int i = 1; i <= n; i ++ )
	// 	cout << f[i] << endl;


	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
		ans ^= f[i] * i;

	printf("%lld\n", ans);

	return 0;
}