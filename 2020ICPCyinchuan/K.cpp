#include <bits/stdc++.h>

using namespace std;

const int N = 2500005, M = 50005;

int n;
int cnt;
unordered_set<unsigned long long> S;
unsigned long long f[55];
int pos[M];
string s[M];

int ch[N][28];
int tot, fa[N], leave[N];

int get(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a';
    else if (c == '.') return 26;
    else return 27;
}

void add(string s)
{
    int u = 0, p = -1, siz = 0;
    for (int i = 0; s[i]; i ++ )
    {
        int v = get(s[i]);
        if (ch[u][v] == 0)
        {
            ch[u][v] = ++ tot;
            fa[ch[u][v]] = u;
            if (p == -1)
                p = u;
        }
        u = ch[u][v];
    }

    for (int i = 0; i < 28; i ++ )
        ch[u][i] = 0;

    if (p == -1) 
        siz = leave[u];

    while (u != -1)
    {
        leave[u] -= siz - 1;
        u = fa[u];
    }

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        cin >> s[i];

    for (int i = n; i >= 1; i -- )
    {
        int sz = s[i].size();
        for (int j = 1; j <= sz; j ++ )
            f[j] = f[j - 1] * 131 + get(s[i][j - 1]) + 1;

        for (int j = 1; j <= sz; j ++)
        {
            if (!S.count(f[j]))
            {
                pos[i] = j;
                break;
            }   
        }

        for (int j = 1; j <= sz; j ++ )
            S.insert(f[j]);
    }

    fa[0] = -1;
    for (int i = 1; i <= n; i ++ )
    {
        string prev = s[i].substr(0, pos[i]);
        // cout << "prev = " << prev << endl;
        add(prev);
        printf("%d\n", leave[0]);
    }

    return 0;
}