#include <iostream>

using namespace std;

int main()
{
	int t;cin >> t;
	while (t --)
	{
		int a, b ;
		cin >> a >> b;
		if (!a) 
		{
			cout << 1 << endl;
			continue;
		}
		cout << a + 2 * b + 1 << endl;
	}
	return 0;
}