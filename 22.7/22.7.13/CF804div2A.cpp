#include <iostream>

using namespace std;

int n;

int main()
{
	int t;cin >> t;
	while (t -- )
	{
		cin >> n;
		if (n % 2) cout << "-1" << endl;
		else cout << 0 << " " << n / 2 << " " << n / 2 << endl;
	}
	return 0;
}