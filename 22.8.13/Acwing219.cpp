#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_set>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 205, mod = 1000000007;

int f[N][N];

int sg(int n, int m)
{
    if (f[n][m] != -1) return f[n][m];
    unordered_set<int> vis;
    for (int i = 2; i <= n - 2; i ++ ) 
        vis.insert(sg(i, m) ^ sg(n - i, m));
    for (int i = 2; i <= m - 2; i ++ )
        vis.insert(sg(n, i) ^ sg(n, m - i));
    
    for (int i = 0;; i ++ )
        if (!vis.count(i))
            return f[n][m] = f[m][n] = i;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    memset(f, -1, sizeof f);
    int n, m;
    f[2][2] = f[2][3] = f[3][2] = f[3][3] = 0;
    while (cin >> n >> m)
        cout << (sg(n, m) ? "WIN" : "LOSE") << endl;
    return 0;
}
