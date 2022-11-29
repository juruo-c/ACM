#include <bits/stdc++.h>

using namespace std;

int n;
string s[20];
bool vis[20];
int sg[1 << 20][26];

int dfs(int cur, char last)
{
    int x = last - 'a';
    if (last != ' ' && sg[cur][x] != -1) return sg[cur][x];
    if (cur == (1 << n) - 1) return 0;
    sg[cur][x] = 0;
    for (int i = 1; i <= n; i ++ )
        if (!(cur >> (i - 1) & 1) && (last == ' ' || last == s[i][0]))
            sg[cur][x] += !dfs(cur | (1 << (i - 1)), s[i][s[i].size() - 1]);
    if (sg[cur][x]) sg[cur][x] = 1;
    return sg[cur][x];
}

int main()
{
    memset(sg, -1, sizeof sg);
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> s[i];
    
    printf("%s\n", dfs(0, ' ') ? "First" : "Second");

    return 0;
}