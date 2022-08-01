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

const int N = 100005, mod = 1000000007;

string T;
string s[15];

struct Seq
{
    int l, r, id;
    bool operator < (const Seq& b) const
    {
        return l < b.l;
    }
}seq[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t;cin >> t;
    while (t --)
    {
        cin >> T;
        int m = T.size();
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i ++ )
        {
            cin >> s[i];
            for (int j = 0; j < m; j ++ )
                if (T.substr(j, min((int)s[i].size(), m - j)) == s[i])
                    seq[++ cnt] = {j, j + (int)s[i].size() - 1, i};
        }

        sort(seq + 1, seq + 1 + cnt);

        // for (int i = 1; i <= cnt; i ++ )
        //     cout << seq[i].id << " " << seq[i].l << " " << seq[i].r << endl;

        vector<PII> ans;
        int r = -1;
        for (int i = 1; i <= cnt; i ++ )
        {
            int mxr = -1, idx = 0;
            int j = i;
            while (j <= cnt && seq[j].l <= r + 1)
            {
                if (mxr < seq[j].r)
                {
                    mxr = seq[j].r;
                    idx = j;   
                }
                j ++;
            }
            // cout << "i = " << i << " r = " << r << " idx = " << idx << endl;
            if (r == m - 1) break;
            if (mxr == -1) break;
            ans.push_back(make_pair(seq[idx].id, seq[idx].l));
            i = j - 1;
            r = mxr;
        }

        if (r < m - 1) puts("-1");
        else 
        {
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); i ++ )
                printf("%d %d\n", ans[i].first, ans[i].second + 1);

        }

    }
    return 0;
}
