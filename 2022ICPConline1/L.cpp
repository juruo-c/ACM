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

const int N = 500005;

int n, m;
char s[N], t[N], ss[N];
bool vis[26];
bool st[26][26];
int f[N][26];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s%s", &s, &t);
    m = strlen(t);

    for (int i = 0; i < m; i ++ )
    {
        for (int j = 0; j < 26; j ++ )
            if (vis[j]) st[j][t[i] - 'a'] = true;
        vis[t[i] - 'a'] = true;
    }

    int cnt = 0;
    for (int i = 0; s[i]; i ++ )
        if (vis[s[i] - 'a'])
            ss[n ++] = s[i];
        else cnt ++;

    for (int i = 0; i < n; i ++ )
        f[i][ss[i] - 'a'] = 1;

    for (int i = 1; i < n; i ++ )
    {
        for (int j = 0; j < 26; j ++ )
        {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            if (!st[j][ss[i] - 'a'])
                f[i][ss[i] - 'a'] = max(f[i][ss[i] - 'a'], f[i - 1][j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i ++ )
        ans = max(ans, f[n - 1][i]);
    printf("%d\n", ans + cnt);

    return 0;
}
