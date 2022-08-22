#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

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
        int n, m;
        cin >> n >> m;
        string s;
        for (int i = 0; i < m; i ++ ) s += 'B';
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            cin >> x;
            int t = m + 1 - x;
            if (x > t) swap(x, t);
            if (s[x - 1] != 'A') s[x - 1] = 'A';
            else s[t - 1] = 'A';
        }
        cout << s << endl;
    }
    return 0;
}
