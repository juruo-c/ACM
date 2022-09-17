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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ )
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1, r = a[0];
    for (int i = 1; i < n; i ++ )
        if (a[i] - r >= k) 
        {
            ans ++;
            r = a[i];
        }
    cout << ans << endl;
    return 0;
}
