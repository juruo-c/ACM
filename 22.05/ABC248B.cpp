#include <iostream>

using namespace std;

typedef long long LL;

bool vis[10];


int main()
{
	LL a, b;
	int k;
	cin >> a >> b >> k;
	int ans = 0;
	while (a < b)
	{
		ans ++;
		a *= k;
	}
	cout << ans << endl;
	return 0;
}