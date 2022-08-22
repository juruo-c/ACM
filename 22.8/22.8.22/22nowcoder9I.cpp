#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 8005, INF = 0x3f3f3f3f;

int n, a[N];
int f[N][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++ )
        f[1][i] = max(f[1][i - 1], a[i]);

    for (int i = 2; i <= n; i ++ )
    {
        stack<int> as, fs, mis;
        as.push(INF), mis.push(INF);
        for (int j = i; j <= n; j ++ )
        {
            int mi = f[i - 1][j - 1];
            while (as.size() && a[j] >= as.top()) 
            {
                mi = min(mi, fs.top());
                fs.pop();
                as.pop();
                mis.pop();
            }
            f[i][j] = min(mi + a[j], mis.top());
            as.push(a[j]);
            fs.push(mi);
            mis.push(f[i][j]);
        }
    }

    for (int i = 1; i <= n; i ++ )
        printf("%d\n", f[i][n]);

    return 0;
}
