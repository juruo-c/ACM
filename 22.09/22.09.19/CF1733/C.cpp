#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> a;
vector<PII> res;
vector<PII> ans;

void solve(vector<PII>& b, vector<int>& a, int who)
{
    int pos = 0, cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i] % 2 == who)
        {
            if (!pos) cnt = 1;
            else cnt ++;
            pos = i;
        }
        else if (pos)
        {
            b.push_back(make_pair(pos, cnt));
            pos = 0;
        }
    }
    if (pos)
        b.push_back(make_pair(pos, cnt));
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
        scanf("%d", &n);
        a.clear();
        a.push_back(0);
        for (int i = 1; i <= n; i ++ )
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        
        res.clear();
        solve(res, a, a[1] % 2);
        res.push_back(make_pair(n + 1, 1));

        int sz = res.size();
        // for (int i = 0; i <= sz - 1; i ++ )
        //     cout << "res = " << res[i].first << " " << res[i].second << endl;
        ans.clear();
        for (int i = 0; i <= sz - 3; i ++ )
            ans.push_back(make_pair(res[i].first, res[sz - 2].first));
        for (int i = 0; i <= sz - 2; i ++ )
        {
            int x = res[i].first, pre = res[i].first - res[i].second + 1, nxt = res[i + 1].first - res[i + 1].second;
            for (int j = pre; j < x; j ++ )
                ans.push_back(make_pair(j, x));
            for (int j = nxt; j > x; j -- )
                ans.push_back(make_pair(j, x));
        }

        printf("%d\n", ans.size());
        sz = ans.size();
        for (int i = 0; i < sz; i ++ )
        {
            if (ans[i].first > ans[i].second) swap(ans[i].first, ans[i].second);
            printf("%d %d\n", ans[i].first, ans[i].second);
        }

    }
    return 0;
}