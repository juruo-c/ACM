#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

int n, k;
int c[N << 1];

struct Node
{
    int a, id;
    bool operator < (const Node& b) const 
    {
        return a > b.a;
    }
}a[N];

void update(int x, int kk)
{
    for (int i = x; i <= n + k; i += (i & -i))
        c[i] += kk;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += c[i];
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    LL ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i].a), a[i].id = i, ans += 1LL * i * i * a[i].a;

    for (int i = k + 1; i <= n + k; i ++ )
        update(i, 1);

    // for (int i = k + 1; i <= n + k; i ++ )
    //     printf("i = %d ans = %d\n",i ,query(i));

    LL res = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++ )
    {
        int L = max(k + 1, a[i].id);
        int l = L;
        int r = n + k;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            // printf("mid = %d L = %d ans = %d\n", mid, L, query(mid) - query(L - 1));
            if (query(mid) - query(L - 1)) r = mid;
            else l = mid + 1;
        }
        res += 1LL * l * l * a[i].a;
        // printf("a[i].id = %d l = %d\n", a[i].id, l);
        update(l, -1);
    }

    printf("%lld\n", res - ans);
    
    return 0;
}
