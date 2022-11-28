#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

int n, m;
string s[N];
unordered_map<string, int> c1, c2;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        cin >> s[i];
    
    for (int i = 0; i < m; i ++ )
    {
        string ss;
        for (int j = 1; j <= n; j ++ )
            ss += s[j][i];
        c1[ss] ++;
    }

    for (int i = 1; i <= n; i ++ ) cin >> s[i];
    for (int i = 0; i < m; i ++ )
    {
        string ss;
        for (int j = 1; j <= n; j ++ )
            ss += s[j][i];
        c2[ss] ++;
    }

    bool flag = true;
    for (auto it : c1)
        if (c2[it.first] != it.second)
        {
            flag = false;
            break;
        }
    for (auto it : c2)
        if (c1[it.first] != it.second)
        {
            flag = false;
            break;
        }

    if (!flag) cout << "No";
    else cout << "Yes";

    return 0;
}