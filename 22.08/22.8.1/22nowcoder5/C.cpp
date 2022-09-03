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

const int N = 100005, mod = 1000000007;

int n;
vector<int> v[N];
char s[5];

void solve()
{
    bool flag = false;
    for (int i = 0; i < n; i ++ )
        if (v[i].size() == 0)
        {
            flag = true;
            break;
        }

    if (flag)
    {
        puts("-1");
        return;
    }

    flag = false;
    int pos = -1;
    for (int i = 0; i < n; i ++ )
    {
        int x = v[i][0];
        for (int j = 1; j < v[i].size(); j ++ )
            if (x != v[i][j])
            {
                pos = i;
                flag = true;
                break;
            }
        if (flag)
            break;
    }

    if (flag)
    {
        if (v[pos].size() == 2)
        {    
            puts("-1");
            return;
        }
        else 
        {
            for (int i = 0; i < n; i ++ )
                if (i == pos)
                {
                    int zerocnt = 0;
                    for (int j = 0; j < v[i].size(); j ++ )
                        if (v[i][j] == 0) zerocnt ++;
                    if (zerocnt == 1) printf("1");
                    else printf("0");
                }
                else printf("%d", v[i][0]);
            puts("");
        }
    }
    else 
    {
        for (int i = 0; i < n; i ++ )
            if (v[i].size() == 1)
            {
                flag = true;
                break;
            }

        if (flag)
        {
            puts("-1");
            return;
        }
        else 
        {
            for (int i = 0; i < n; i ++ ) printf("%d", v[i][0]);
            puts("");
        }
    }
    
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i ++ )
            v[i].clear();

        for (int i = 1; i <= 3 * n; i ++ )
        {
            int k;
            scanf("%d %s", &k, s);
            if (s[0] == 'Y')
                v[k].push_back(1);
            else v[k].push_back(0);   
        }

        solve();

    }
    return 0;
}
