#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 10005;

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		int n, m;
		cin >> n >> m;
		cout << 1LL * m * (m - 1) / 2 + 1LL * n * (n + 1) / 2 * m << endl;
	}
	return 0;
}