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

const int N = 300005, mod = 1000000007;

int n;
int ans;
char s[N];
struct PAM
{
    int sz, tot, last;
    int cnt[N], ch[N][26], len[N], fail[N];
    char s[N];

    int node(int l)
    {
        sz ++;
        memset(ch[sz], 0, sizeof(ch[sz]));
        len[sz] = l;
        fail[sz] = cnt[sz] = 0;
        return sz;
    }

    void clear()
    {
        sz = -1;
        last = 0;
        s[tot = 0] = '$';
        node(0);
        node(-1);
        fail[0] = 1;
    }

    int getfail(int x)
    {
        while (s[tot - len[x] - 1] != s[tot]) x = fail[x]; // 找最长回文后缀
        return x;
    }

    void insert(char c)
    {
        s[++ tot] = c;
        int now = getfail(last);
        if (!ch[now][c - 'a'])
        {
            int x = node(len[now] + 2);
            fail[x] = ch[getfail(fail[now])][c - 'a'];
            ch[now][c - 'a'] = x;
        }
        last = ch[now][c - 'a'];
        cnt[last] ++;
    }
}pam[5];

void dfs(vector<int>& path, int depth)
{
    if (depth) ans ++;
    for (int i = 0; i < 26; i ++ )
    {
        bool flag = true;
        for (int j = 0; j < n; j ++ )
        {
            if (!pam[j].ch[path[j]][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            vector<int> next = path;
            for (int j = 0; j < n; j ++ )
                next[j] = pam[j].ch[path[j]][i];
            dfs(next, depth + 1);
        }
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        pam[i].clear();
        scanf("%s", s);
        for (int j = 0; s[j]; j ++ )
            pam[i].insert(s[j]);
    }

    vector<int> a(n, 0), b(n, 1);
    dfs(a, 0);dfs(b, 0);

    printf("%d\n", ans);

    return 0;
}
