#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 105;

int n, a[N];
int f[45];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    map<LL, int> pos;
    pos[1] = 0, pos[2] = 1;
    LL s = 2;
    f[0] = f[1] = 1;
    for (int i = 2; i <= 43; i ++ ) 
    {
        f[i] = f[i - 1] + f[i - 2];
        s += f[i];
        pos[s] = i;
    }
    
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);

        LL sum = 0;
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), sum += a[i];

        if (pos.find(sum) == pos.end())
        {
            puts("NO");
            continue;
        }

        bool flag = true;

        int last = 0;
        for (int i = pos[sum]; i >= 0; i -- )
        {
            int k = 0;
            for (int j = 1; j <= n; j ++ )
            {
                if (j == last) continue;
                if (a[j] > a[k]) k = j;
            }
            if (a[k] >= f[i])
                a[k] -= f[i], last = k;
            else
            {
                flag = false;
                break;
            }
        }

        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
