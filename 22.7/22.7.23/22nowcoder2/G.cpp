#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1000005;

int ans[N];

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        cin >> n;
        int t = sqrt(n);
        if (t * t != n) t ++;
        for (int i = n; i >= 1; i -= t)
        {
            int l = max(1, i - t + 1);
            for (int j = l, k = i; j <= i; j ++, k --)
                ans[j] = k;
        }

        for (int i = 1; i <= n; i ++ )
        {
            if (i > 1) cout << " " ;
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}