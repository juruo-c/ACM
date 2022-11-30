#include <iostream>

using namespace std;

const int N = 500005;

int n;
int a[N];
bool vis[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n + 1; i ++ ) vis[i] = false;
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (!vis[a[i] + 1]) ans ++;
            vis[a[i]] = true;
        }
        printf("%d\n", ans);
    }
    return 0;
}