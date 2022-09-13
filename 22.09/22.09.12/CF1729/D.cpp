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

const int N = 100005;

int n;
int a[N], b[N];

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
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        vector<int> t;
        multiset<int> s;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d", &b[i]);
            if (b[i] - a[i] >= 0)
                s.insert(b[i] - a[i]);
            else t.push_back(b[i] - a[i]);
        }
        sort(t.begin(), t.end());
        int tsz = t.size();

        // for (int i = 0; i < t.size(); i ++ )
        //     cout << t[i] << " ";
        // cout << endl;

        int ans = 0;
        for (int i = 0; i < tsz; i ++ )
        {
            multiset<int>::iterator it = s.lower_bound(-t[i]);
            if (it != s.end())
            {
                ans ++;
                s.erase(it);
            }
        }
        ans += s.size() / 2;
        printf("%d\n", ans);
    }
    return 0;
}
