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

const int N = 200005, mod = 998244353;

int n;
char s[N];
char t[N];
int ch[N][26];
int tot;
int fail[N], last[N];
int ed[N];
int f[N];
int len[N], val[N];
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void insert(char s[], int idx)
{
    int u = 0;
    for (int i = 0; s[i]; i ++ )
    {
        int v = s[i] - 'a';
        if (!ch[u][v]) ch[u][v] = ++ tot;
        u = ch[u][v];
    }
    ed[u] = idx;
}

void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i ++ )
        if (ch[0][i]) q.push(ch[0][i]), add(0, ch[0][i]);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i ++ )
        {
            if (ch[u][i])
            {
                fail[ch[u][i]] = ch[fail[u]][i];
                add(fail[ch[u][i]], ch[u][i]);
                q.push(ch[u][i]);
            }
            else ch[u][i] = ch[fail[u]][i];
        }
    }
}

void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (ed[u] == -1) last[v] = last[u];
        else last[v] = u;
        dfs(v);
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    memset(ed, -1, sizeof ed);

    scanf("%s", s);
    n = strlen(s);
    int _;
    scanf("%d", &_);
    ed[0] = 0;
    for (int i = 1; i <= _; i ++ )
    {
        scanf("%s", t), insert(t, i);
        scanf("%d", &val[i]);
        len[i] = strlen(t);
    }

    get_fail();

    dfs(0);
    // for (int i = 1; i <= n; i ++ )
    //     cout << "i = " << i << " fail[i] = " << fail[i] << endl;


    // for (int i = 1; i <= n; i ++ )
    //     cout << "i = " << i << " last[i] = " << last[i] << endl;

    // for (int i = 1; i <= n; i ++ )
    //     cout << "i = " << i << " ed[i] = " << ed[i] << endl;

    f[0] = 1;
    int u = 0;
    for (int i = 0; s[i]; i ++ )
    {
        int v = s[i] - 'a';
        u = ch[u][v];

        int t = u;
        if (ed[u] == -1) t = last[t];
        while (t)
        {
            // cout << "u = " << u << endl;
            f[i + 1] = (f[i + 1] + 1LL * f[i - len[ed[t]] + 1] * val[ed[t]] % mod) % mod;
            t = last[t];
        }

        f[i + 1] = (f[i + 1] + f[i]) % mod;
    }

    for (int i = 1; i <= n; i ++ )
        printf("%d ", f[i]);
    puts("");

    return 0;
}
