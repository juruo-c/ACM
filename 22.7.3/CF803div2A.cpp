#include <iostream>

using namespace std;

const int N = 105;

int n;
int a[N];

int main()
{
	int t; cin >> t;
	while (t --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		for (int i = 1; i <= n; i ++ ) 
		{
			int x = 0;
			for (int j = 1; j <= n; j ++ )
				if (j != i) x ^= a[j];
			if (x == a[i])
			{
				cout << a[i] << endl;
				break;
			}
		}
	}
	return 0;
}