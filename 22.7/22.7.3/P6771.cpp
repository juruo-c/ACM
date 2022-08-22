#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 405, M = 40005;

int n, m;
struct Goods
{
	int h, a, c;
	bool operator < (const Goods& g) const
	{
		return a < g.a;
	}
}good[N];
bool f[M];

int main()
{
	// freopen("1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d%d%d", &good[i].h, &good[i].a, &good[i].c);

	sort(good + 1, good + 1 + n);

	// for (int i = 1; i <= n; i ++ )
	// 	cout << good[i].h << " " << good[i].a << " " << good[i].c << endl;

	f[0] = true;
	for (int i = 1; i <= n; i ++ )
		for (int j = good[i].a; j >= 0; j -- )
			for (int k = 1; k <= good[i].c && k * good[i].h <= j; k ++ )
				f[j] |= f[j - k * good[i].h];

	for (int i = good[n].a; i >= 0; i -- )
		if (f[i])
		{
			printf("%d\n", i);
			break;
		}
	return 0;
}