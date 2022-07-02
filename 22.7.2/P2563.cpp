#include <iostream>
#include <cstring>

using namespace std;

const int N = 205;

int n;
bool vis[N];
int p[N];
int f[N];

void prime()
{
	for (int i = 2; i < N; i ++ )
	{
		if (!vis[i])
			p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && p[j] * i < N; j ++ )
		{
			vis[i * p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
	}
}

int main()
{
	prime();
	while (~scanf("%d", &n))
	{
		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int i = 1; i <= p[0]; i ++ )
			for (int j = p[i]; j <= n; j ++ )
				f[j] += f[j - p[i]];
		printf("%d\n", f[n]);
	}
	return 0;
}