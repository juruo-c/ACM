#include <iostream>

using namespace std;

const int N = 1000005;

int n;
char s[N];
bool vis[N];

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i ++ ) vis[i] = false;
        long long ans = 0;
        for (int i = n, j = n - 1; i >= 1; i -- )
        {
            if (vis[i]) continue;
            while (j >= i) j --;
            while (j && s[j] == '0') j -- ;
            if (j) ans += j;
            vis[j] = true;
            if (j) j --;
        }
        printf("%lld\n", ans);
    }
    return 0;
}