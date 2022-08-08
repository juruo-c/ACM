#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int a[N];

int main()
{
	int t;cin >> t;
	while (t --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		sort (a + 1, a + 1 + n);
		cout << a[n] + a[n - 1] << endl;
	}
	return 0;
}