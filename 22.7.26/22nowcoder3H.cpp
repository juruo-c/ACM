#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

struct Node
{
    int ch[26];
    int len, fa;
    Node(){memset(ch, 0, sizeof ch); len = 0;}
};

struct SAM
{
    Node point[N << 1];
    int last, tot;
    SAM()
    {
        last = 1, tot = 1;
    }

    void add(int c)
    {
        int p = last;
        int np = last = ++ tot;
        point[np].len = point[p].len + 1;
        for (; p && !point[p].ch[c]; p = point[p].fa) point[p].ch[c] = np;
        if (!p) point[np].fa = 1;
        else
        {
            int q = point[p].ch[c];
            if (point[q].len == point[p].len + 1) point[np].fa = q;
            else
            {
                int nq = ++ tot;
                point[nq] = point[q];
                point[nq].len = point[p].len + 1;
                point[q].fa = point[np].fa = nq;
                for (; p && point[p].ch[c] == q; p = point[p].fa) point[p].ch[c] = nq;
            }
        }
    }

}sam;

int n, m, k;
LL v[N];
char s[N];
LL st[N][20];
int lg[N];

void st_init()
{
    for (int i = 2; i <= m + 1; i ++ )
        lg[i] = lg[i / 2] + 1;
        
    for (int i = 2; i <= m + 1; i ++ )
        st[i][0] = v[i - 1];
    for (int j = 1; j < 20; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= m + 1; i ++ )
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); 
}

LL st_query(int l, int r)
{
    int k = lg[(r - l + 1) / 2];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i ++ )
            sam.add(s[i] - 'a');
        
        for (int i = 1; i <= m; i ++ )
            scanf("%lld", &v[i]), v[i] += v[i - 1];

        st_init();

        for (int i = 1; i <= k; i ++ )
        {
            scanf("%s", s + 1);
            int p = 1, len = 0;
            LL ans = 0;
            for (int j = 1; j <= m; j ++ )
            {
                int c = s[j] - 'a';
                // cout << "j = " << j << " p = " << p << " len = " << len << " point[p].ch[c] = " << sam.point[p].ch[c] << endl;
                while (p && !sam.point[p].ch[c]) p = sam.point[p].fa, len = sam.point[p].len;
                if (!p) p = 1, len = 0;
                else
                {
                    p = sam.point[p].ch[c];
                    len ++;
                }
                if (len)
                {
                    // cout << "i = " << i << " j = " << j << " len = " << len << endl;
                    int r = j, l = r - len + 1;
                    ans = max(ans, v[r] - st_query(l, r + 1));
                }
            }
            printf("%lld\n", ans);
        }

    }
    return 0;
}
