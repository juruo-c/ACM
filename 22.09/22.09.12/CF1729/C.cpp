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

const int N = 200005;

int n;
char s[N];
int cnt[26];
vector<int> idx[26];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < 26; i ++ )
            idx[i].clear();
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i ++ )
            cnt[s[i] - 'a'] ++, idx[s[i] - 'a'].push_back(i);
        
        int l = s[1] - 'a';
        int r = s[n] - 'a';

        int ans = 0;
        bool flag = false;
        if (l > r) swap(l, r), flag = true;

        int cur = l;
        vector<int> res;
        for (int i = l; i <= r; i ++ )
            if (cnt[i])
            {
                ans += i - cur;
                cur = i;
                int t = cnt[i];
                for (int j = 0; j < t; j ++ )
                    if (idx[i][j] != 1 && idx[i][j] != n)
                        res.push_back(idx[i][j]);
            }

        if (flag) reverse(res.begin(), res.end());

        printf("%d %d\n", ans, res.size() + 2);
        printf("%d ", 1);
        for (int i = 0; i < res.size(); i ++ )
            printf("%d ", res[i]);
        printf("%d ", n);
        puts("");

    }
    return 0;
}
