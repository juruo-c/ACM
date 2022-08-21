#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; cin >> _;
    while (_ --)
    {
        LL n, k, b, s;
        cin >> n >> k >> b >> s;
        vector<LL> ans;
        LL t = k * b;
        if (t > s)
        {
            puts("-1");
            continue;
        }
        LL a1 = t;
        s -= t;
        if (s >= k - 1) a1 += k - 1, s -= k - 1;
        else a1 += s, s = 0;
        ans.push_back(a1);
        bool flag = true;
        while (s)
        {
            if (s >= k - 1) s -= k - 1, ans.push_back(k - 1);
            else ans.push_back(s), s = 0;
            if (ans.size() > n)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            while (ans.size() < n) ans.push_back(0);
            for (int i = 0; i < ans.size(); i ++ )
                cout << ans[i] << " ";
            cout << endl;
        }
        else puts("-1");
    }
    return 0;
}
