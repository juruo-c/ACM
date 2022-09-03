//http://oj.daimayuan.top/course/10/problem/468

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 105, mod = 998244353;

int n, k;
bool vis[N];

int main()
{
    cin >> n >> k;
    int ans = 0;
    LL sum = (1LL << k);

    for (int i = 1; i <= n; i ++ )
    {
        LL a;
        cin >> a;
        int cnt = 0;
        for (int j = 0; j < k; j ++ )
            if (!vis[j] && (a & (1LL << j))) vis[j] = true;
            else if (!vis[j]) cnt ++;

        ans = (ans + (sum - (1LL << cnt)) * i % mod) % mod;
        sum = (1LL << cnt);
    }

    cout << ans << endl;
    return 0;
}
