#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], vis[N], n;
int main()
{
    scanf("%d", &n);
    int mi = 1e9, mx = 0;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), mi = min(mi, a[i]), mx = max(mx, a[i]);
    mi *= 2, mx *= 2;
    int ans = 0;
    for(int i = mx; i >= mi; i --)
    {
        memset(vis, 0, sizeof vis);
        int last = 0, cnt = 0;
        for(int j = 1; j <= n; j ++)
        {
            if(i <= a[j]) continue;
            if(vis[i - a[j]] > last)
            {
                last = j;
                cnt += 2;
            }
            else vis[a[j]] = j;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}