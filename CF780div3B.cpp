#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200005;

int n;
int a[N];

int main()
{
	int t;scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
		if (n == 1)
		{
			if (a[n] > 1) cout << "NO" << endl;
			else cout << "YES" << endl;
			continue;
		}
		sort(a + 1, a + 1 + n);
		if (a[n] > a[n - 1] + 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}