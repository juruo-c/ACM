#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ZYCMH

using namespace std;

typedef pair<int, int> PII;

char a[10], b[10];

bool B[10];
int P[10];
int G[10];

bool vis[10];
int cnt[10];

bool check(int i, int j, int k)
{
    vector<int> c(10);
    c[0] = i / 10, c[1] = i % 10;
    c[3] = j / 10, c[4] = j % 10;
    c[6] = k / 10, c[7] = k % 10;

    for (int i = 0; i < 10; i ++ )
        cnt[i] = 0;
    for (int j = 0; j <= 7; j ++ )
        if (j != 2 && j != 5)
            cnt[c[j]] ++;

    for (int j = 0; j <= 7; j ++ )
    {
        if (j == 2 || j == 5) continue;
        if (b[j] == 'G')
        {
            if (c[j] != a[j] - '0') return false;
        }
        else 
        {
            if (c[j] == a[j] - '0') return false;
            if (b[j] == 'B')
            {
                if (cnt[a[j] - '0'] != G[a[j] - '0'] + P[a[j] - '0']) 
                    return false;
            }
        }
    }

    for (int i = 0; i < 10; i ++ )
        if (cnt[i] - G[i] < P[i]) return false;
    
    return true;
            
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%s", a);
    scanf("%s", b);

    for (int i = 0; b[i]; i ++ )
        if (b[i] == 'B')
            B[a[i] - '0'] = true;
        else if(b[i] == 'P')
            P[a[i] - '0'] ++;
        else if (b[i] == 'G' && a[i] != '+' && a[i] != '=') 
            G[a[i] - '0'] ++;
    
    vector<PII> ans;
    for (int i = 0; i <= 99; i ++ )
        for (int j = 0; j <= 99; j ++ )
            if (i + j <= 99 && check(i, j, i + j))
                ans.push_back(make_pair(i, j));

    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++ )
        printf("%d%d+%d%d=%d%d\n", ans[i].first / 10, ans[i].first % 10, ans[i].second / 10, ans[i].second % 10, (ans[i].first + ans[i].second) / 10, (ans[i].first + ans[i].second) % 10);
    return 0;
}