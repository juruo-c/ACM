#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2005;

int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-')
            f = -1;
        c= getchar();
    }
    while(isdigit(c)){
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int n, m;
struct Edge
{
	int to, next, w;
}e[N << 1];
int head[N], cnt;
int siz[N];
LL f[N][N];

void add(int u, int v, int w)
{
	e[++ cnt] = Edge{v, head[u], w};
	head[u] = cnt;
}

void dfs(int u, int ff)
{
	siz[u] = 1;
	f[u][0] = f[u][1] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].to;
		if (v == ff) continue;
		dfs(v, u);
		siz[u] += siz[v];
		for (int j = min(siz[u], m); j >= 0; j -- )
			for (int k = 0; k <= min(j, siz[v]); k ++ )
			{
				if (f[u][j - k] == -1) continue;
				LL tot = 1LL * k * (m - k) + (n - m - siz[v] + k) * (siz[v] - k);
				f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] + e[i].w * tot);
			}
	}
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i < n; i ++ ) 
	{
		int u = read(), v = read(), w = read();
		add(u, v, w);
		add(v, u, w);
	}

	memset(f, -1, sizeof f);
	dfs(1, 0);

	printf("%lld\n", f[1][m]);

	return 0;
}