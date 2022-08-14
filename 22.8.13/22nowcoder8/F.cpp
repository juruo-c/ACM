#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; cin >> t;
    while (t --)
    {
        unordered_map<int, int> pos;
        int n, m, p, x, a, b, c;
        cin >> n >> m >> p >> x >> a >> b >> c;
        for (int i = 1; i <= n; i ++ )
        {
            x = ( 1LL * a * x % p * x % p + 1LL * b * x % p + c) % p;
            if (!pos[x]) pos[x] = i;
        }
        bool flag = false;
        for (int i = 1; i <= m; i ++ )
        {
            x = ( 1LL * a * x % p * x % p + 1LL * b * x % p + c) % p;
            if (pos[x]) 
            {
                cout << min(n - pos[x] + 1, m - i + 1) << endl;
                flag = true;
                break;
            }
        }

        if (!flag) cout << "0" << endl;
    }
    return 0;
}
