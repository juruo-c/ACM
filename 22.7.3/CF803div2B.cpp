#include <iostream>
 
using namespace std;
 
const int N = 200005;
 
int n, k;
int a[N];
 
int main()
{
	int t; cin >> t;
	while (t --)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		int ans = 0;
		for (int i = 2; i < n; i ++ ) if (a[i] > a[i - 1] + a[i + 1]) ans ++;
		if (k >= 2) cout << ans << endl;
		else cout << (n - 1) / 2 << endl;
	}
	return 0;
}