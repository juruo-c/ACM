#include <iostream>
#include <algorithm>

using namespace std;

int a[11];
int f[11];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    
    int n = 4;

    for (int i = 1; i <= n; i ++ )
        a[i] = i;
    
    int ans = n;
    do
    {
        /* code */
        for (int i = 1; i <= n; i ++ ) f[i] = 1;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j < i; j ++ )
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        
        int res = 0;
        for (int i = 1; i <= n; i ++ )
            res = max(res, f[i]);

        for (int i = 1; i <= n; i ++ ) f[i] = 1;
        for (int i = n; i >= 1; i -- )
            for (int j = n; j > i; j -- )
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        
        for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);

        ans = min(ans, res);

    } while (next_permutation(a + 1, a + 1 + n));
    
    cout << ans << endl;

    return 0;
}
