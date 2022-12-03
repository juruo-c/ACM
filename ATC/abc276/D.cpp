#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL k; cin >> k;
    LL ans = 0;
    for (LL i = 2; i * i <= k; i ++ )
        if (k % i == 0)
        {
            int c = 0;
            while (k % i == 0) k /= i, c ++;
            
            int res = 1; c --;
            while (c > 0)
            {
                res ++;
                LL t = res * i;
                while (t % i == 0) t /= i, c --;
            }
            ans = max(ans, res * i);
        }
    if (k != 1) ans = max(ans, k);
    cout << ans;
    return 0;
}