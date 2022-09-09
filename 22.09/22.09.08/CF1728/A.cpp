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

int calc(vector<int>& a)
{
    int x = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (x < a[i])
            x += a[i];
        else x = 0;
    return x;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i ++ )
            a[i] = i + 1;
        vector<int> ans;
        int mx = 0;
        do
        {
            /* code */
            int t = calc(a);
            if (t > mx) mx = t, ans = a;
        } while (next_permutation(a.begin(), a.end()));
        cout << calc(ans) << endl;
        for (int i = 0; i < n; i ++ )
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
