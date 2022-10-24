#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ZYCMH

using namespace std;

typedef pair<int, int> PII;

const int N = 200005;

int n;
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 

    int _;
    scanf("%d", &_);
    while(_ --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

        if (n % 2)
        {
            puts("-1");
            continue;
        }

        int c1 = 0, c0 = 0;
        for (int i = 1; i <= n; i ++ )
            if (a[i] > 0) c1 ++;
            else c0 ++;
        
        if (c0 > c1)
        {
            for (int i = 1; i <= n; i ++ )
                if (a[i] > 0) a[i] = -1;
                else a[i] = 1;
            swap(c1, c0);
        }
        else if(c0 == c1)
        {
            printf("%d\n", n);
            for (int i = 1; i <= n; i ++ )
                printf("%d %d\n", i, i);
            continue;
        }

        vector<PII> ans;
        int i, k = c1 - c0;
        k /= 2;
        for (i = 1; i < n; i ++ )
        {
            if (!k) break;
            if (a[i] == 1 && a[i + 1] == 1)
                ans.push_back({i, i + 1}), i ++, k --;
            else ans.push_back({i, i});
        }
        for (; i <= n; i ++ )
            ans.push_back({i, i});
        
        printf("%d\n", ans.size());
        for(auto x : ans)
            printf("%d %d\n", x.first, x.second);
    }

    return 0;
}