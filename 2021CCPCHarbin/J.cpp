#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;

int a[N][N];
int mir[N], mic[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i ++ )
        mir[i] = 1e9;
    for (int i = 1; i <= m; i ++ )
        mic[i] = 1e9;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            mir[i] = min(mir[i], a[i][j]);
        
    for (int j = 1; j <= m; j ++ )
        for (int i = 1; i <= n; i ++ )
            mic[j] = min(mic[j], a[i][j]);

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (min(mir[i], mic[j]) == a[i][j])
                ans ++;
    printf("%d\n", ans);
    return 0;
}