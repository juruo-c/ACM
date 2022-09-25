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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    vector<int> b, c;
    b.push_back(a[1]);
    for (int i = 2; i <= n; i ++ )
        if (a[i] > a[i - 1])
            b.push_back(a[i]);
        else break;
    
    c.push_back(a[n]);
    for (int i = n - 1; i >= 1; i -- )
        if (a[i] > a[i + 1])
            c.push_back(a[i]);
        else break;

    int l = 0, r = 0;
    int lsz = b.size(), rsz = c.size();
    int who = 0;
    bool flag = false;
    while (l < lsz && r < rsz)
    {
        int llen = (lsz - l);
        int rlen = (rsz - r);
        if (b[l] == c[r] && (llen % 2 || rlen % 2) ) 
        {
            flag = true;
            break;
        } 
        if (b[l] > c[r])
        {
            if (llen % 2)
            {
                flag = true;
                break;
            }
            else r ++, who ^= 1;      
        }
        else 
        {
            if (rlen % 2)
            {
                flag = true;
                break;
            }
            else l ++, who ^= 1;
        }
    }

    if (flag)
    {
        printf("%s\n", who ? "Bob" : "Alice");
        return 0;
    }
    if (l < lsz) 
    {
        if ((lsz - l) % 2 == 0)
            who ^= 1;
    }
    if (r < rsz)
    {
        if ((rsz - r) % 2 == 0)
            who ^= 1;
    }

    printf("%s\n", who ? "Bob" : "Alice");
    return 0;
}
