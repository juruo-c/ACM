#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10005;

int n;
int a[N];

bool ask(int l, int r)
{
	cout << "? " << l << " " << r << endl << endl;
	cout.flush();
	int c = 0;
	for (int i = l; i <= r; i ++ )
	{
		cin >> a[i];
		if (a[i] < l || a[i] > r) c ++;
	}

	return (r - l + 1 - c) % 2;

}

int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		cin >> n;
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (ask(l, mid)) r = mid;
			else l = mid + 1;
		}
		cout << "! " << r << endl << endl;
		cout.flush();
	}
	return 0;
}
