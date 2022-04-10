#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1 << 16;

int n;
int a[N];

void dfs(int l, int r, int num)
{
	if (l > r) return;
	int mid = l + r >> 1;
	a[mid] = num;
	if (l == r) return;
	dfs(l, mid - 1, num - 1);
	dfs(mid + 1, r, num - 1);
}

int main()
{
	int n; cin >> n;
	dfs(1, (1 << n) - 1, n);
	for (int i = 1; i < (1 << n); i ++ )
		cout << a[i] << " ";
	cout << endl;
	return 0;
}