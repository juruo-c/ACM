#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 100005;

int n;
int a[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin >> t;
	while(t -- )
	{
		unordered_map<int, int> num;
		cin >> n;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];

		int mxnum = 0;
		for (int i = 1; i <= n; i ++ )
		{
			num[a[i]] ++;
			if (num[a[i]] > mxnum) mxnum = num[a[i]];
		}

		int ans = 0;
		while(mxnum < n)
		{
			int d = min(n - mxnum, mxnum);
			ans += 1 + d;
			mxnum += d;
		}

		cout << ans << "\n";	
	}
	return 0;
}