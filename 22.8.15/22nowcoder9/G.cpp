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

const int N = 600005, mod = 1000000007;
map<string, int> cnt;

struct SAM
{
    int ch[N][26], len[N], fa[N];
    string S[N];
    int last, tot;

    void sam_init()
    {
        for (int i = 1; i <= tot; i ++ ) S[i] = "";
        last = tot = 1;
        memset(ch, 0, sizeof ch);
        memset(len, 0, sizeof len);
        memset(fa, 0, sizeof fa);
    }

    void add(int c)
    {
        int p = last;
        int np = last = ++ tot;
        len[np] = len[p] + 1;
        for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if (!p) fa[np] = 1;
        else
        {
            int q = ch[p][c];
            if (len[q] == len[p] + 1) fa[np] = q;
            else 
            {
                int nq = ++ tot;
                for (int i = 0; i < 26; i ++ ) ch[nq][i] = ch[q][i];
                fa[nq] = fa[q];
                len[nq] = len[p] + 1;
                fa[q] = fa[np] = nq;
                for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
    }

    void dfs(int u, string s)
    {
        S[u] = s;
        for (int i = 0; i < 26; i ++ )
            if (ch[u][i])
            {
                string t; t += char(i + 'a');
                dfs(ch[u][i], s + t);
            }
    }

    void solve(int u, string& s)
    {
        int cur = 1;
        for (int i = 0; s[i]; i ++ )
        {
            int c = s[i] - 'a';
            while (cur && !ch[cur][c]) cur = fa[cur];
            if (cur)
            {
                cur = ch[cur][c];
                if (cnt[S[cur]] < u) cnt[S[cur]] ++;
            } 
            else cur = 1;
        }
    }
}sam;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        sam.sam_init();
        string s;
        cin >> s;
        for (int j = 0; s[j]; j ++ )
            sam.add(s[j]);
        reverse(s.begin(), s.end());
        sam.dfs(1, "");
        sam.solve(i, s);
    }

    cout << "over" << endl;

    int ans = 0;
    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it ++)
        if (it->second == n) ans ++;
    
    cout << ans << endl;
    return 0;
}
