#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
const int N = 100005, mod = 1000000007;
 
int k;
int a[N];
 
bool solve(int n, int m)
{
    LL c1 = 0, c2 = 0;
    bool flag = false;
    for (int i = 1; i <= k; i ++ )
    {
        LL t = a[i] / n;
        if(t >= 2)
            c1 += t / 2 * 2, c2 += t % 2;
        if (t / 2 * 2 > 2) flag = true;
    }
    
    if (c1 >= m)
    {
        if (m % 2) return c2 >= 1 || flag;
        else return true;
    }
    else
        return c1 + c2 >= m;
}
 
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, m;
        scanf("%d%d%d", &n, &m, &k);
        bool flag = false;
        for (int i = 1; i <= k; i ++ )
            scanf("%d", &a[i]);
 
        if (solve(n, m) || solve(m, n))
            puts("YES");
        else
            puts("NO");
        
    }
    return 0;
}