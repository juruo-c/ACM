#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 200005;

int n, q;
vector<int> a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		int x;scanf("%d", &x);
		a[x].push_back(i);
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++ )
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		printf("%d\n", upper_bound(a[x].begin(), a[x].end(), r) - lower_bound(a[x].begin(), a[x].end(), l));
	}
	return 0;
}