#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int L, G;

int main()
{
	int t;cin >> t;
	while (t --)
	{
		cin >> G >> L;
		if (L % G) cout << 0 << endl;
		else
		{
			long long ans = 1;
			L /= G;
			for (int i = 2; i * i <= L; i ++ )
			{
				if (L % i == 0)
				{
					int cnt = 0;
					while(L % i == 0)
						L /= i, cnt ++;
					ans *= cnt * 6;
				}
			}
			if (L != 1) ans *= 6;
			cout << ans << endl;
		}

	}
	return 0;
}