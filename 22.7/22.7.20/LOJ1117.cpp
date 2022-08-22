#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, m;
int a[N];

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

LL LCM(LL a, LL b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    int kase = 0;
    while (t -- )
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i ++ )
            cin >> a[i];

        long long ans = n;
        for (int i = 1; i < 1 << m; i ++ )
        {
            long long t = 1;
            bool flag = 0;
            for (int j = 0; j < m; j ++ )
                if (i & (1 << j))
                    t = LCM(t, a[j + 1]), flag ^= 1;

            if (flag) ans -= n / t;
            else ans += n / t;

        }

        cout << "Case " << ++kase << ": " << ans << endl;

    }
    return 0;
}