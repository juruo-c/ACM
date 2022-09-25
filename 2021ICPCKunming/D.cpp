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
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "4\n";
        cout << "3 4 1 2\n";
        return 0;
    }
    if (k == 1)
    {
        cout << "6\n";
        cout << "1 1 4 5 1 4\n";
        return 0;
    }

    vector<int> ans;
    int i;
    for (i = 30; i >= 0; i -- )
        if (k >> i & 1) break;
    
    int cur = 1;
    int t = i;
    while (t --)
        ans.push_back(cur);
    cur ++;
    
    for (int j = i - 1; j >= 0; j -- )
    {
        if (k >> j & 1)
        {
            if (j == 0) ans.push_back(cur);
            else 
            {
                int t = j;
                while (t --)
                    ans.push_back(cur);
                cur ++;
                ans.push_back(cur);
                cur ++;
            }
        }
    }

    cout << ans.size() << endl;
    t = ans.size();
    for (int i = 0; i < t; i ++ )
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
